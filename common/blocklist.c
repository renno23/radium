/* Copyright 2000 Kjetil S. Matheussen

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


#include <string.h>
#include "nsmtracker.h"
#include "player_proc.h"
#include "list_proc.h"
#include "undo_playlist_proc.h"
#include "OS_Bs_edit_proc.h"

#include "blocklist_proc.h"

extern struct Root *root;

// Note: talloc_atomic could be used instead of talloc, since the blocks are stored elsewhere.
// However, in case of bugs, using talloc_atomic here could lead to crashes that would be very hard to find the origin of.


void BL_init(void){
#ifdef TRACKER_DEBUG
	int lokke;
#endif

	root->song->playlist=talloc(sizeof(struct Blocks *));
	root->song->playlist[0]=root->song->blocks;
	root->song->length=1;

	/*
#ifdef TRACKER_DEBUG
	debug("playlen: %d\n",root->song->length);
	for(lokke=0;lokke<root->song->length;lokke++){
		debug("pos: %d, block: %d\n",lokke,root->song->playlist[lokke]->l.num);
	}
#endif
	*/
}

int *BL_copy(void){
  int *playlist = talloc_atomic(sizeof(int)*(root->song->length+1));
  int pos;
  playlist[0] = root->song->length;
  for(pos=0;pos<root->song->length;pos++)
    playlist[pos+1]=root->song->playlist[pos]->l.num;
  return playlist;
}

void BL_paste(int *playlist){
  int len = playlist[0];
  struct Blocks **new=talloc(len*sizeof(struct Blocks *));
  int pos;
  for(pos=0;pos<len;pos++)
    new[pos]=(struct Blocks *)ListFindElement1(&root->song->blocks->l,playlist[pos+1]);

  root->song->length = len;
  root->song->playlist = new;
}

void BL_insert(int pos,struct Blocks *block){
	int lokke;
	struct Blocks **temp;
	struct Blocks **playlist=root->song->playlist;

	root->song->length++;

	temp=talloc(root->song->length*sizeof(struct Blocks *));
	memcpy(temp,playlist,(root->song->length-1)*sizeof(struct Blocks *));

	temp[pos]=block;

	for(lokke=pos;lokke<root->song->length-1;lokke++){
		temp[lokke+1]=playlist[lokke];
	}
	root->song->playlist=temp;

#if 1
	printf("playlen: %d\n",root->song->length);
	for(lokke=0;lokke<root->song->length;lokke++){
	  printf("pos: %d, block: %d\n",lokke,temp[lokke]->l.num);
	}

#endif
}

void BL_insertCurrPos(int pos,struct Blocks *block){
  PlayStop();
  Undo_Playlist();
  BL_insert(pos,block);
  BS_UpdatePlayList();
}

void BL_delete(int pos){
	int lokke;

	struct Blocks **playlist=root->song->playlist;

	for(lokke=pos;lokke<root->song->length;lokke++){
		playlist[lokke]=playlist[lokke+1];
	}

	root->song->length--;

        if(root->song->length==0) { // Illegal with length 0.
          playlist[0] = root->song->blocks;
          root->song->length = 1;
        }
          

#if 1
	printf("||||||||||| playlen: %d\n",root->song->length);
	for(lokke=0;lokke<root->song->length;lokke++){
	  printf("pos: %d, block: %d\n",lokke,playlist[lokke]->l.num);
	}
	printf("||||||||||| playlen: %d\n",root->song->length);
#endif

}

void BL_deleteCurrPos(int pos){
  PlayStop();
  Undo_Playlist();
  BL_delete(pos);
  BS_UpdatePlayList();
}

struct Blocks *BL_GetBlockFromPos(int pos){
	if(pos>=root->song->length || pos<0) return NULL;
	return root->song->playlist[pos];
}

static int get_first_block_pos(struct Blocks *block){
  int pos;

  for(pos=0;pos<root->song->length;pos++)
    if(root->song->playlist[pos]==block)
      return pos;

  return -1;
}

void BL_removeBlockFromPlaylist(struct Blocks *block){
  while(get_first_block_pos(block)!=-1){
    if(block==root->song->blocks && root->song->length==1){ // special case
      printf("what?\n");
      break;
    }
    BL_delete(get_first_block_pos(block));
  }
}
