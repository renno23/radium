/* Copyright 2005 Kjetil S. Matheussen

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. */





#include "../nsmtracker.h"
#include "../placement_proc.h"
#include "../clipboard_range_calc_proc.h"
#include "../list_proc.h"
#include "../wtracks_proc.h"
#include "../undo_notes_proc.h"
#include "../undo_range_proc.h"
#include "../visual_proc.h"
#include "../player_proc.h"
#include "../player_pause_proc.h"

#include "pitchexpand_proc.h"

static int minnote;
static int maxnote;

#define SCALE(x,x1,x2,y1,y2) ((y1)+(((x)-(x1))*((y2)-(y1)))/((x2)-(x1)))

static void PExpand_SetMinMax(
			      struct Notes *note,
			      Place *p1,
			      Place *p2,
			      bool firsttime
			      )
{
	if(note==NULL) return;

	if(PlaceGreaterOrEqual(&note->l.p,p1)){

		if(PlaceGreaterOrEqual(&note->l.p,p2)) return;

		if(firsttime==false){
		  maxnote=R_MAX(note->note,maxnote);
		  minnote=R_MIN(note->note,minnote);
		}else{
		  minnote=127;
		  maxnote=0;
		  firsttime=false;
		}
	}

	PExpand_SetMinMax(NextNote(note),p1,p2,firsttime);
}


static void PExpand_DoIt(
	struct Notes *note,
	Place *p1,
	Place *p2,
	float scalefactor
){
	if(note==NULL) return;
        if(minnote==maxnote) return;

	if(PlaceGreaterOrEqual(&note->l.p,p1)){
	  float midnote;
	  if(PlaceGreaterOrEqual(&note->l.p,p2)) return;

	  midnote=(minnote+maxnote)/2.0f;

	  note->note=(int) (0.5f + SCALE(note->note, 
                                         minnote, 
                                         maxnote, 
                                         midnote - ( (midnote-minnote) * scalefactor),
                                         midnote + ( (midnote-minnote) * scalefactor)
                                         )
                            );
	  note->note=R_MAX(1,R_MIN(127,note->note));

	}

	PExpand_DoIt(NextNote(note),p1,p2,scalefactor);
}


void PExpandRange(
		  struct WBlocks *wblock,
		  float scalefactor
){
	struct Tracks *track;
	int lokke;
	bool firsttime=true;
	Place *p1,*p2;

	if( ! wblock->isranged) return;

	p1=getRangeStartPlace(wblock);
	p2=getRangeEndPlace(wblock);

	track=ListFindElement1(&wblock->block->tracks->l,wblock->rangex1);

	for(lokke=0;lokke<=wblock->rangex2-wblock->rangex1;lokke++){
	  PExpand_SetMinMax(track->notes,p1,p2,firsttime);
	  firsttime=false;
	  track=NextTrack(track);
	}

	track=ListFindElement1(&wblock->block->tracks->l,wblock->rangex1);
	for(lokke=0;lokke<=wblock->rangex2-wblock->rangex1;lokke++){
	  PExpand_DoIt(track->notes,p1,p2,scalefactor);
	  track=NextTrack(track);
	}

}

void PExpandTrack(
	struct Blocks *block,
	struct Tracks *track,
	float scalefactor
){
	Place p1,p2;

	PlaceSetFirstPos(&p1);
	PlaceSetLastPos(block,&p2);
	
	PExpand_SetMinMax(track->notes,&p1,&p2,true);
	
        PExpand_DoIt(track->notes,&p1,&p2,scalefactor);
}

void PExpandBlock(
		  struct Blocks *block,
		  float scalefactor
){
	struct Tracks *track;
	bool firsttime=true;
	Place *p1,p2;
	//float midnote;
	
	//printf("Scale %f\n",scalefactor);
	p1=PlaceGetFirstPos();
	PlaceSetLastPos(block,&p2);

	track=block->tracks;

	while(track!=NULL){
	  PExpand_SetMinMax(track->notes,p1,&p2,firsttime);
	  firsttime=false;
	  track=NextTrack(track);
	}
	//midnote=(minnote+maxnote)/2.0f;	
	//printf("midnote: %f, m1:%d/%d, m2: %f/%f\n", midnote,minnote,maxnote, midnote - ( (midnote-minnote) * scalefactor), midnote + ( (midnote-minnote) * scalefactor));

	track=block->tracks;
	while(track!=NULL){
	  PExpand_DoIt(track->notes,p1,&p2,scalefactor);
	  track=NextTrack(track);
	}
}


static float GetScaleFactor(struct Tracker_Windows *window){
  ReqType reqtype;
  float ret;

  PlayStop();
  reqtype=GFX_OpenReq(window,33,5,"Pitch scale factor");
  ret=GFX_GetFloat(window,reqtype,"Pitch scale factor: ",0.0f,10.0f);
  GFX_CloseReq(window,reqtype);
  return ret;
}


void PExpandRange_CurrPos(
			  struct Tracker_Windows *window,
			  float scalefactor
){
	if(!window->wblock->isranged) return;

	while(scalefactor<0)
	  scalefactor=GetScaleFactor(window);

	Undo_Range(
		window,
		window->wblock->block,
		window->wblock->rangex1,
		window->wblock->rangex2,
		window->wblock->curr_realline
	);

	PExpandRange(window->wblock,scalefactor);

	UpdateAndClearSomeTrackReallinesAndGfxWTracks(
		window,
		window->wblock,
		window->wblock->rangex1,
		window->wblock->rangex2
	);

}

void PExpandTrack_CurrPos(
			  struct Tracker_Windows *window,
			  float scalefactor
){

	while(scalefactor<0)
	  scalefactor=GetScaleFactor(window);

	Undo_Notes_CurrPos(window);

	PExpandTrack(window->wblock->block,window->wblock->wtrack->track,scalefactor);

	UpdateAndClearSomeTrackReallinesAndGfxWTracks(
		window,
		window->wblock,
		window->wblock->wtrack->l.num,
		window->wblock->wtrack->l.num
	);

}


void PExpandBlock_CurrPos(
			  struct Tracker_Windows *window,
			  float scalefactor
){

	while(scalefactor<0)
	  scalefactor=GetScaleFactor(window);

	Undo_Range(
		window,
		window->wblock->block,
		0,window->wblock->block->num_tracks-1,
		window->wblock->curr_realline
	);

	PExpandBlock(window->wblock->block,scalefactor);

	UpdateAndClearSomeTrackReallinesAndGfxWTracks(
		window,
		window->wblock,
		0,
		window->wblock->block->num_tracks-1
	);

}









