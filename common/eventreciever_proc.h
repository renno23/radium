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


bool Quit(struct Tracker_Windows *window);

#ifdef TRACKER_INCLUDE

int TreatAllEvents(struct Tracker_Windows *window);
void DontTreatAnyEvents(struct Tracker_Windows *window);
void DontTreatAnyEvents_AndDontBuffer(struct Tracker_Windows *window);
int TreatEvents(int ID,struct Tracker_Windows *window);
void DontTreatEvents(int ID,struct Tracker_Windows *window);

#endif

#ifndef TRACKER_INCLUDE

extern LANGSPEC int EventReciever(struct TEvent *tevent,struct Tracker_Windows *window);
extern int TreatAllEvents(struct Tracker_Windows *window);
extern void DontTreatAnyEvents(struct Tracker_Windows *window);
extern void DontTreatAnyEvents_AndDontBuffer(struct Tracker_Windows *window);
extern int TreatEvents(int ID,struct Tracker_Windows *window);
extern void DontTreatEvents(int ID,struct Tracker_Windows *window);

#endif
