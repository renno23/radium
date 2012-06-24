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


#include <string.h>

#define GFX_DONTSHRINK

#include "nsmtracker.h"

#include "visual_op_queue_proc.h"

#include "visual_proc.h"

#include "gfx_op_queue_proc.h"


enum{
#  define OP_ENUMS
#  include "gfx_op_queue_generated.c"
#  undef OP_ENUMS
};


typedef struct{
  int type;
  int i1;
  union{
    int i2;
    char s2[64];
  };
  int i3;
  int i4;
  union{
    int i5;
    bool b5;
  };
  int i6;
  int i7;
  int i8;
} queue_element_t;

typedef struct{
  queue_element_t *elements;
  int pos;
  int size;
} queue_t;

void GFX_play_op_queue(struct Tracker_Windows *window){
  queue_t *queue = window->op_queue;
  int i;

  //fprintf(stderr,"queue size: %d\n",queue->pos);

  for(i=0;i<queue->pos;i++){
    queue_element_t *el = &queue->elements[i];
    switch(el->type){
#     define OP_CASES
#     include "gfx_op_queue_generated.c"
#     undef OP_CASES
    default:
      RError("Unknown type %d",el->type);
    }
  }

  queue->pos = 0;
}

void GFX_create_op_queue(struct Tracker_Windows *window){
  window->op_queue = talloc(sizeof(queue_t));
}

int GFX_get_op_queue_size(struct Tracker_Windows *window){
  queue_t *queue = window->op_queue;
  return queue->pos;
}

static void grow_queue(queue_t *queue){
  int new_size = queue->size==0 ? 16 : queue->size*2;
  queue_element_t *new_elements = talloc_atomic(sizeof(queue_element_t)*new_size);
  memset(new_elements,0,sizeof(queue_element_t)*new_size); // needed for oversized strings to terminate

  memcpy(new_elements, queue->elements, sizeof(queue_element_t)*queue->size);

  queue->elements = new_elements;
  queue->size = new_size;
}

static queue_element_t *get_next_element(queue_t *queue){
  if(queue->pos==queue->size)
    grow_queue(queue);
  return &queue->elements[queue->pos++];
}


#define OP_FUNCS
#include "gfx_op_queue_generated.c"
#undef OP_FUNCS

