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





#include <unistd.h>

#include "nsmtracker.h"
#include "disk.h"
#include "disk_root_proc.h"
#include "OS_disk_proc.h"
#include "disk_save_proc.h"
#include "visual_proc.h"
#include "player_proc.h"
#include "undo.h"
#include "nag.h"
#include "OS_settings_proc.h"

#include "../config/config.h"


void Save_Clean(const wchar_t *filename,struct Root *theroot){
	int length1,length2;

	dc.success=true;

        dc.file=DISK_open_for_writing(filename);
	if(dc.file==NULL){
		RError("Could not open file for writing.\n");
		return;
	}

        OS_set_saving_path(filename);
        
	length1=DISK_write(dc.file,"RADIUM SONG\n");
	length2=DISK_printf(dc.file,"%s\n",OS_get_string_from_double(DISKVERSION));

	if(length1<0 || length2<0){
		RError("Could not write to file.\n");
                DISK_close_and_delete(dc.file);
		return;
	}

	DC_start("OSSTUFF");
		SaveOsStuff();
	DC_end();

	SaveRoot(theroot);

	if( ! dc.success){
		RError("Problems writing to file.\n");
	}

        DISK_close_and_delete(dc.file);
#if 0
	if(fclose(dc.file)==EOF){
		RError("Could not close file. Out of disk-space?\n");
		RError("Saving failed.\n");
                return;
	}
#endif
        Undo_saved_song();

        show_nag_window("File successfully saved.<p>");
}

void SaveAs(struct Root *theroot){
	const wchar_t *filename;

	PlayStop();

	filename=GFX_GetSaveFileName(theroot->song->tracker_windows, NULL," Select file to save", NULL, NULL);

	if(filename==NULL) return;

#ifndef GUIISQT // Qt asks this question for us.
	char *ret=NULL;
	if( ! access(filename,F_OK)){
		while(
			ret==NULL || (
				! strcmp("yes",ret) &&
				! strcmp("no",ret)
			)
		){
			ret=GFX_GetString(
				theroot->song->tracker_windows,
				NULL,
				"File allready exists, are you shure? (yes/no)"
			);
		}
		if(!strcmp("no",ret)) return;
	}
#endif
	dc.filename=filename;

        GFX_SetWindowTitle(theroot->song->tracker_windows,filename);

	Save_Clean(filename,theroot);

}

void Save(struct Root *theroot){

	PlayStop();

	if(dc.filename==NULL){
		SaveAs(theroot);
	}else{
		Save_Clean(dc.filename,theroot);
	}
}

