/* Copyright 2012 Kjetil S. Matheussen

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


#ifndef SOUNDPRODUCER_PROC_H
#define SOUNDPRODUCER_PROC_H

#ifdef __cplusplus

#include <stdint.h>
#include <vector>

#include "SoundPlugin.h"

struct DoublyLinkedList{
  DoublyLinkedList *next;
  DoublyLinkedList *prev;

  DoublyLinkedList()
  : next(NULL)
  , prev(NULL)
  {    
  }

  void add(DoublyLinkedList *l){
    l->next = this->next;
    if(this->next!=NULL)
      this->next->prev = l;
    this->next = l;
    l->prev = NULL;
  }

  void remove(DoublyLinkedList *l){
    if(l->prev!=NULL)
      l->prev->next = l->next;
    else
      this->next = l->next;
    if(l->next!=NULL)
      l->next->prev = l->prev;
  }
};

struct SoundProducer;

SoundProducer *SP_create(SoundPlugin *plugin);
void SP_delete(SoundProducer *producer);
bool SP_add_elink(SoundProducer *target, SoundProducer *source);
bool SP_add_link(SoundProducer *target, int target_ch, SoundProducer *source, int source_ch);
void SP_remove_elink(SoundProducer *target, SoundProducer *source);
void SP_remove_link(SoundProducer *target, int target_ch, SoundProducer *source, int source_ch);
void SP_remove_all_links(std::vector<SoundProducer*> soundproducers);
void SP_RT_process(SoundProducer *producer, int64_t time, int num_frames, bool process_plugins);
void SP_RT_process_bus(float **outputs, int64_t time, int num_frames, int bus_num, bool process_plugins);
void SP_RT_set_bus_descendant_type_for_plugin(SoundProducer *producer);
struct SoundPlugin *SP_get_plugin(SoundProducer *producer);
SoundProducer *SP_get_SoundProducer(SoundPlugin *plugin);
float SP_get_input_peak(SoundProducer *producer, int ch);
float SP_get_output_peak(SoundProducer *producer, int ch);
void SP_set_buffer_size(SoundProducer *producer,int buffer_size);

#endif // __cplusplus

extern LANGSPEC bool SP_replace_plugin(SoundPlugin *old_plugin, SoundPlugin *new_plugin);
extern LANGSPEC bool SP_is_plugin_running(SoundPlugin *plugin);

#endif // SOUNDPRODUCER_PROC_H
