/* Copyright 2013 Kjetil S. Matheussen

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

/*

Serious bug:
============
* Fixed for now by doing:

diff --git a/Qt/Qt_instruments.cpp b/Qt/Qt_instruments.cpp
index 738826d..b9aaadd 100644
--- a/Qt/Qt_instruments.cpp
+++ b/Qt/Qt_instruments.cpp
@@ -763,7 +763,7 @@ void GFX_remove_patch_gui(struct Patch *patch){
 
 void GFX_update_instrument_patch_gui(struct Patch *patch){
   printf("Called GFX_update_instrument_patch_gui for patch \"%s\"\n",patch==NULL?"<>":patch->name);
-  if(patch!=NULL && patch->instrument->PP_Update!=NULL)
+  if(patch!=NULL && patch->patchdata!=NULL && patch->instrument->PP_Update!=NULL)
     patch->instrument->PP_Update(patch->instrument,
                                  patch);

But I'm not sure if this is a proper fix.



Terminal output and backtrace:


####################################################### Setting pd volume to 0.000000 / real_value: 0.000000, for -frequency-
*(((( EFFNUM_OUTPUT_VOLUME. val: -0.002502. MIN_DB: -40. Target: 0.999424. plugin->volume: 0.999712
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
####################################################### Setting pd volume to 0.000000 / real_value: 0.000000, for -frequency-
Calling Undo_do for 74. Current value: 0.000000. Now setting it back to 1.000000
*(((( EFFNUM_OUTPUT_VOLUME. val: -0.002502. MIN_DB: -40. Target: 0.999424. plugin->volume: 0.999712
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Calling Undo_do for 74. Current value: 1.000000. Now setting it back to 0.000000
*(((( EFFNUM_OUTPUT_VOLUME. val: -0.002502. MIN_DB: -40. Target: 0.999424. plugin->volume: 0.999712
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Calling Undo_do for 0. Current value: 0.008900. Now setting it back to 0.163000
####################################################### Setting pd volume to 0.163000 / real_value: 0.163000, for -volume-
*(((( EFFNUM_OUTPUT_VOLUME. val: -0.002502. MIN_DB: -40. Target: 0.999424. plugin->volume: 0.999712
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
####################################################### Setting pd volume to 0.163000 / real_value: 0.163000, for -volume-
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
*** undo_do_track called. Tracknum: 0
Called GFX_update_instrument_patch_gui for patch "<>"
Called GFX_update_instrument_patch_gui for patch "Pd 2"
Calling Undo_do for 2. Current value: 0.532300. Now setting it back to 0.000000
####################################################### Setting pd volume to 0.000000 / real_value: 0.000000, for -volume2-
*(((( EFFNUM_OUTPUT_VOLUME. val: -0.002502. MIN_DB: -40. Target: 0.999424. plugin->volume: 0.999712
Called GFX_update_instrument_patch_gui for patch "<>"
Called GFX_update_instrument_patch_gui for patch "Pd 1"
0 set to 1

Program received signal SIGSEGV, Segmentation fault.
0x00000000004a9b9e in Audio_instrument_widget::Audio_instrument_widget (this=0x3149210, parent=0x114c380, patch=0x13c6540) at Qt/Qt_audio_instrument_widget_callbacks.h:96
96	    if(plugin->type->play_note==NULL)
Missing separate debuginfos, use: debuginfo-install OpenEXR-libs-1.7.0-4.fc17.x86_64 boost-system-1.48.0-14.fc17.x86_64 cyrus-sasl-lib-2.1.23-31.fc17.x86_64 fftw-libs-single-3.3.3-5.fc17.x86_64 flac-1.2.1-9.fc17.x86_64 glibc-2.15-58.fc17.x86_64 glibmm24-2.32.1-1.fc17.x86_64 gsm-1.0.13-6.fc17.x86_64 ilmbase-1.0.2-4.fc17.x86_64 jamin-0.97.16-3.20111031cvs.fc17.x86_64 kdelibs-4.10.5-1.fc17.x86_64 ladspa-calf-plugins-0.0.18.6-6.fc17.x86_64 ladspa-guitarix-plugins-0.25.2-1.fc17.x86_64 ladspa-wasp-plugins-0.9.5.1-2.fc17.x86_64 libcurl-7.24.0-6.fc17.x86_64 libidn-1.24-1.fc17.x86_64 liblo-0.26-4.fc17.x86_64 liblrdf-0.5.0-3.fc17.x86_64 libsigc++20-2.2.10-2.fc17.x86_64 libssh2-1.4.1-2.fc17.x86_64 libvorbis-1.3.3-1.fc17.x86_64 libxml2-2.7.8-9.fc17.x86_64 libxslt-1.1.26-10.fc17.x86_64 nspr-4.9.6-1.fc17.x86_64 nss-3.14.3-1.fc17.x86_64 nss-softokn-freebl-3.14.3-1.fc17.x86_64 nss-util-3.14.3-1.fc17.x86_64 openldap-2.4.33-3.fc17.x86_64 qt-4.8.4-17.fc17.x86_64 qt-x11-4.8.4-17.fc17.x86_64 qt4-theme-quarticurve-0.0-0.17.beta8.fc17.x86_64 raptor2-2.0.7-1.fc17.x86_64 xz-libs-5.1.2-1alpha.fc17.x86_64 yajl-2.0.4-1.fc17.x86_64
(gdb) p plugin
$1 = (SoundPlugin *) 0x0
(gdb) bt
#0  0x00000000004a9b9e in Audio_instrument_widget::Audio_instrument_widget (this=0x3149210, parent=0x114c380, patch=0x13c6540) at Qt/Qt_audio_instrument_widget_callbacks.h:96
#1  0x0000000000480762 in create_audio_instrument_widget (patch=0x13c6540) at Qt/Qt_instruments.cpp:373
#2  0x000000000048142c in GFX_PP_Update (patch=0x13c6540) at Qt/Qt_instruments.cpp:714
#3  0x00000000005935ac in AUDIO_PP_Update (instrument=0x10c9e60, patch=0x13c6540) at audio/audio_instrument.c:315
#4  0x00000000004815f8 in GFX_update_instrument_patch_gui (patch=0x13c6540) at Qt/Qt_instruments.cpp:768
#5  0x0000000000464444 in Undo () at common/undo.c:307
#6  0x00000000004ce809 in undo () at api/api_undo.c:37
#7  0x000000000043da6c in ER_gotKey (key=72, a=2, down=true) at common/eventreciever.c:187
#8  0x000000000043dc56 in EventTreater (in_tevent=0x99d6b0, window=0x132ec40) at common/eventreciever.c:241
#9  0x000000000043e0a3 in EventReciever (in_tevent=0x99d6b0, window=0x132ec40) at common/eventreciever.c:352
#10 0x00000000004d06d5 in X11Event_KeyPress (keynum=72, keystate=4, window=0x132ec40) at X11/X11_keyboard.c:274
#11 0x00000000004d0768 in X11_KeyPress (event=0x7fffffffc790, window=0x132ec40) at X11/X11_keyboard.c:285
#12 0x00000000004d091c in X11_KeyboardFilter (event=0x7fffffffc790) at X11/X11_keyboard.c:332
#13 0x000000000046ade2 in MyApplication::x11EventFilter (this=0xe94e40, event=0x7fffffffc790) at Qt/Qt_Main.cpp:107
#14 0x000000334aa3681c in ?? () from /lib64/libQtGui.so.4
#15 0x000000334aa43e1b in QApplication::x11ProcessEvent(_XEvent*) () from /lib64/libQtGui.so.4
#16 0x000000334aa6a90c in ?? () from /lib64/libQtGui.so.4
#17 0x00007ffff7cf3825 in g_main_dispatch (context=0xe96c40) at gmain.c:2539
#18 g_main_context_dispatch (context=context@entry=0xe96c40) at gmain.c:3075
#19 0x00007ffff7cf3b58 in g_main_context_iterate (context=context@entry=0xe96c40, block=block@entry=1, dispatch=dispatch@entry=1, self=<optimized out>) at gmain.c:3146
#20 0x00007ffff7cf3c14 in g_main_context_iteration (context=0xe96c40, may_block=1) at gmain.c:3207
#21 0x000000334a3a5e96 in QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /lib64/libQtCore.so.4
#22 0x000000334aa6a5ee in ?? () from /lib64/libQtGui.so.4
#23 0x000000334a37651f in QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) () from /lib64/libQtCore.so.4
#24 0x000000334a3767a8 in QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) () from /lib64/libQtCore.so.4
#25 0x000000334a37b638 in QCoreApplication::exec() () from /lib64/libQtCore.so.4
#26 0x0000000000469f8b in radium_main (arg=0x7ffff10c052c "") at Qt/Qt_Main.cpp:530
#27 0x00000000004cba06 in init_radium (arg=0x7ffff10c052c "", gkf=<function at remote 0x7ffff0cf3aa0>) at api/api_common.c:61
#28 0x00000000004c6a38 in _wrap_init_radium (self=0x0, args=('', <function at remote 0x7ffff0cf3aa0>)) at api/radium_wrap.c:572
#29 0x00000039c1edd0e1 in call_function (oparg=<optimized out>, pp_stack=0x7fffffffce78) at /usr/src/debug/Python-2.7.3/Python/ceval.c:4098
#30 PyEval_EvalFrameEx (f=f@entry=Frame 0x102c7c0, for file /home/kjetil/radium-qt4/bin/start.py, line 137, in <module> (), throwflag=throwflag@entry=0) at /usr/src/debug/Python-2.7.3/Python/ceval.c:2740
#31 0x00000039c1eddb1f in PyEval_EvalCodeEx (co=co@entry=0x7ffff0fdf0b0, globals=globals@entry=
    {'false': 0, 'keyhandles': [<KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000ea8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000d40>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000d88>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0ceaf38>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0ceafc8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4050>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4098>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf40e0>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4128>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4170>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf41b8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4200>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4248>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4290>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf42d8>, <KeyHandler(keyslist=...(truncated), 
    locals=locals@entry=
    {'false': 0, 'keyhandles': [<KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000ea8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000d40>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff1000d88>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0ceaf38>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0ceafc8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4050>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4098>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf40e0>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4128>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4170>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf41b8>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4200>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4248>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf4290>, <KeyHandler(keyslist=[], handlers=[]) at remote 0x7ffff0cf42d8>, <KeyHandler(keyslist=...(truncated), 
    args=args@entry=0x0, argcount=argcount@entry=0, kws=kws@entry=0x0, kwcount=kwcount@entry=0, defs=defs@entry=0x0, defcount=defcount@entry=0, closure=closure@entry=0x0)
    at /usr/src/debug/Python-2.7.3/Python/ceval.c:3330
#32 0x00000039c1eddbf2 in PyEval_EvalCode (co=co@entry=0x7ffff0fdf0b0, globals=globals@entry=

                                */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#include <libpds.h>

#include <QTemporaryFile>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>

#include "../common/nsmtracker.h"
#include "SoundPlugin.h"
#include "SoundPlugin_proc.h"
#include "undo_pd_controllers_proc.h"

#include "../common/OS_Player_proc.h"
#include "../common/OS_settings_proc.h"

#include "../Qt/Qt_pd_plugin_widget_callbacks_proc.h"
#include "SoundPluginRegistry_proc.h"

#include "Qt_instruments_proc.h"

#include "Pd_plugin.h"

#include "Pd_plugin_proc.h"


typedef struct{
  pd_t *pd;

  Pd_Controller controllers[NUM_PD_CONTROLLERS];
  void *file;

  QTemporaryFile *pdfile;

  void *qtgui;
} Data;



static void RT_process(SoundPlugin *plugin, int64_t time, int num_frames, float **inputs, float **outputs){
  Data *data = (Data*)plugin->data;
  pd_t *pd = data->pd;

  libpds_process_float_noninterleaved(pd, num_frames / libpds_blocksize(pd), (const float**) inputs, outputs);
}

static void RT_play_note(struct SoundPlugin *plugin, int64_t time, int note_num, float volume, float pan){
  Data *data = (Data*)plugin->data;
  pd_t *pd = data->pd;
  libpds_noteon(pd, 0, note_num, volume*127);
}

static void RT_set_note_volume(struct SoundPlugin *plugin, int64_t time, int note_num, float volume){
  Data *data = (Data*)plugin->data;
  pd_t *pd = data->pd;
  libpds_polyaftertouch(pd, 0, note_num, volume*127);
}

static void RT_stop_note(struct SoundPlugin *plugin, int64_t time, int note_num, float volume){
  Data *data = (Data*)plugin->data;
  pd_t *pd = data->pd;
  libpds_noteon(pd, 0, note_num, 0);
}

static void RT_set_effect_value(struct SoundPlugin *plugin, int64_t time, int effect_num, float value, enum ValueFormat value_format) {
  Data *data = (Data*)plugin->data;
  pd_t *pd = data->pd;
  Pd_Controller *controller = &data->controllers[effect_num];
  float real_value;

  if(value_format==PLUGIN_FORMAT_SCALED && controller->type!=EFFECT_FORMAT_BOOL)
    real_value = scale(value, 0.0, 1.0, 
                       controller->min_value, controller->max_value);
  else
    real_value = value;

  controller->value = real_value;

  if(strcmp(controller->name, "")) {
    //printf("####################################################### Setting pd volume to %f / real_value: %f, for -%s-. Coming-from-pd: %d\n",value, real_value,name,controller->calling_from_pd);
    controller->calling_from_set_effect_value = true; {

      if(false==controller->calling_from_pd)
        libpds_float(pd, controller->name, real_value);

    } controller->calling_from_set_effect_value = false;
  }
}

static float RT_get_effect_value(struct SoundPlugin *plugin, int effect_num, enum ValueFormat value_format) {
  Data *data = (Data*)plugin->data;
  float raw = data->controllers[effect_num].value;
  if(value_format==PLUGIN_FORMAT_SCALED && data->controllers[effect_num].type!=EFFECT_FORMAT_BOOL)
    return scale(raw, data->controllers[effect_num].min_value, data->controllers[effect_num].max_value,
                 0.0f, 1.0f);
  else
    return raw;
}

static void get_display_value_string(SoundPlugin *plugin, int effect_num, char *buffer, int buffersize){
  Data *data = (Data*)plugin->data;
  Pd_Controller *controller = &data->controllers[effect_num];

  const char *name = controller->name;

  if(controller->type==EFFECT_FORMAT_FLOAT)
    snprintf(buffer,buffersize-1,"%s: %f",!strcmp(name,"")?"<not set>":name, controller->value);
  else
    snprintf(buffer,buffersize-1,"%s: %d",!strcmp(name,"")?"<not set>":name, (int)controller->value);
}

static void show_gui(struct SoundPlugin *plugin){
  Data *data = (Data*)plugin->data;
  //printf("####################################################### Showing Pd gui\n");
  PLAYER_lock();{
    libpds_show_gui(data->pd);
  }PLAYER_unlock();
}

void save_file(SoundPlugin *plugin) {
  Data *data=(Data*)plugin->data;
  libpds_savefile(data->pd, data->file);
}

static void hide_gui(struct SoundPlugin *plugin){
  Data *data = (Data*)plugin->data;
  //printf("####################################################### Showing Pd gui\n");
  PLAYER_lock();{
    libpds_hide_gui(data->pd);
    save_file(plugin);
  }PLAYER_unlock();
}

static void RT_pdfloathook(void *d, const char *sym, float val){
  Pd_Controller *controller = (Pd_Controller*)d;

  //printf("pdfloathook. calling_from_set_effect_value: %s\n",controller->calling_from_set_effect_value?"true":"false");

  if( ! controller->calling_from_set_effect_value) {

    float scaled_value = scale(val, controller->min_value, controller->max_value,
                               0.0f, 1.0f);

    controller->calling_from_pd = true; {
      PLUGIN_set_effect_value(controller->plugin, -1, controller->num, scaled_value, PLUGIN_NONSTORED_TYPE, PLUGIN_STORE_VALUE); // PLUGIN_set_effect_value only works with NONSTORED_TYPE for system effects. (should be fixed)
    } controller->calling_from_pd = false;
  }
}

static void RT_bind_receiver(Pd_Controller *controller){
  char receive_symbol_name[PD_NAME_LENGTH+20];
  snprintf(receive_symbol_name, PD_NAME_LENGTH+19, "%s-receiver", controller->name);
  controller->pd_binding = libpds_bind(((Data*)controller->plugin->data)->pd, receive_symbol_name, controller);
}

static void RT_add_controller(SoundPlugin *plugin, Data *data, const char *controller_name, int type, float min_value, float value, float max_value){
  Pd_Controller *controller;
  int controller_num;
  bool creating_new = true;

  for(controller_num=0;controller_num<NUM_PD_CONTROLLERS;controller_num++) {
    controller = &data->controllers[controller_num];

    if(controller->name != NULL && !strcmp(controller->name, controller_name)) {
      creating_new = false;
      break;
    }

    if(controller->name == NULL || !strcmp(controller->name, ""))
      break;
  }

  if(controller_num==NUM_PD_CONTROLLERS)
    return;

  if (fabs(min_value-max_value) < 0.0001f) {
    if(fabs(min_value) < 0.001f)
      max_value = 1.0f;
    else {
      min_value = value;
      max_value = value + 1.0f;
    }
  }

  controller->type = type;
  controller->min_value = min_value;
  controller->value = value;
  controller->max_value = max_value;  
  strncpy(controller->name, controller_name, PD_NAME_LENGTH-1);

  controller->has_gui = true;

  if (creating_new==true)
    RT_bind_receiver(controller);

  PDGUI_schedule_clearing(data->qtgui);
}

// Note that hooks are always called from the player thread.
static void RT_pdmessagehook(void *d, const char *source, const char *controller_name, int argc, t_atom *argv){
  SoundPlugin *plugin = (SoundPlugin*)d;
  Data *data = (Data*)plugin->data;
  
  if( !strcmp(source, "libpd")) {
    //printf("controller_name: -%s-\n",controller_name);
    if(!strcmp(controller_name, "gui_is_visible"))
      PDGUI_is_visible(data->qtgui);
    else if(!strcmp(controller_name, "gui_is_hidden"))
      PDGUI_is_hidden(data->qtgui);
    return;
  }
}

static void RT_pdlisthook(void *d, const char *recv, int argc, t_atom *argv) {
  SoundPlugin *plugin = (SoundPlugin*)d;
  Data *data = (Data*)plugin->data;
  
  printf("argc: %d\n",argc);

  if( !strcmp(recv, "radium_controller") &&
      argc==5 &&
      libpd_is_symbol(argv[0]) &&
      strcmp("", libpd_get_symbol(argv[0])) &&
      libpd_is_float(argv[1]) &&
      libpd_is_float(argv[2]) &&
      libpd_is_float(argv[3]) &&
      libpd_is_float(argv[4]))
    {
      char  *name      = libpd_get_symbol(argv[0]);
      int    type      = libpd_get_float(argv[1]);
      float  min_value = libpd_get_float(argv[2]);
      float  value     = libpd_get_float(argv[3]);
      float  max_value = libpd_get_float(argv[4]);
      printf("Got something: -%s-, %d, %f, %f, %f\n", name, type, min_value, value, max_value);
      
      if(type==EFFECT_FORMAT_FLOAT || type==EFFECT_FORMAT_INT || type==EFFECT_FORMAT_BOOL)
        RT_add_controller(plugin, data, name, type, min_value, value, max_value);
      else
        printf("Unknown type: -%d-\n",type);
    }
}

static QTemporaryFile *create_temp_pdfile(){
  QString destFileNameTemplate = QDir::tempPath()+QDir::separator()+"radium_XXXXXX.pd";
  return new QTemporaryFile(destFileNameTemplate);
}

static QTemporaryFile *get_pdfile_from_state(hash_t *state){
  QTemporaryFile *pdfile = create_temp_pdfile();
  pdfile->open();

  QTextStream out(pdfile);
  int num_lines = HASH_get_int(state, "num_lines");

  for(int i=0; i<num_lines; i++)
    out << HASH_get_string_at(state, "line", i);

  pdfile->close();

  return pdfile;
}

// http://www.java2s.com/Code/Cpp/Qt/Readtextfilelinebyline.htm
static void put_pdfile_into_state(QFile *file, hash_t *state){
  file->open(QIODevice::ReadOnly | QIODevice::Text);

  QTextStream in(file);

  int i=0;
  QString line = in.readLine();
  while (!line.isNull()) {
    //printf("line: -%s-\n",line.ascii());
    HASH_put_string_at(state, "line", i, line.ascii());
    i++;
    line = in.readLine();
  }

  HASH_put_int(state, "num_lines", i);

  file->close();
}

static QString get_search_path() {
  return QString(OS_get_program_path()) + QDir::separator() + "pd";
}

static Data *create_data(QTemporaryFile *pdfile, struct SoundPlugin *plugin, float sample_rate, int block_size){
  Data *data = (Data*)calloc(1,sizeof(Data));

  int i;
  for(i=0;i<NUM_PD_CONTROLLERS;i++) {
    data->controllers[i].plugin = plugin;
    data->controllers[i].num = i;
    data->controllers[i].max_value = 1.0f;
  }

  int blocksize;
  pd_t *pd;

  char puredatapath[1024];
  snprintf(puredatapath,1023,"%s/packages/libpd-master/pure-data",OS_get_program_path());
  pd = libpds_create(true, puredatapath);
  if(pd==NULL) {
    QMessageBox msgBox;
    msgBox.setText(QString(libpds_strerror()));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    return NULL;
  }

  data->pd = pd;

  QString search_path = get_search_path();
  libpds_add_to_search_path(pd, search_path.ascii());

  libpds_set_floathook(pd, RT_pdfloathook);
  libpds_set_messagehook(pd, RT_pdmessagehook);
  libpds_set_listhook(pd, RT_pdlisthook);

  libpds_init_audio(pd, 2, 2, sample_rate);
    
  blocksize = libpds_blocksize(pd);

  if( (block_size % blocksize) != 0)
    RWarning("PD's blocksize of %d is not dividable by Radium's block size of %d. You will get bad sound. Adjust your audio settings.", blocksize, block_size);

  // compute audio    [; pd dsp 1(
  libpds_start_message(pd, 1); // one entry in list
  libpds_add_float(pd, 1.0f);
  libpds_finish_message(pd, "pd", "dsp");

  plugin->data = data; // plugin->data is used before this function ends. (No, only data, seems like. We can send 'data' instead of 'plugin' to the hooks.) (well, PD_recreate_controllers_from_state uses plugin->data)

  libpds_bind(pd, "radium_controller", plugin);
  libpds_bind(pd, "libpd", plugin);

  data->pdfile = pdfile;

  QFileInfo qfileinfo(pdfile->fileName());
  printf("name: %s, dir: %s\n",qfileinfo.fileName().ascii(), qfileinfo.absolutePath().ascii());

  data->file = libpds_openfile(pd, qfileinfo.fileName().ascii(), qfileinfo.absolutePath().ascii());

  return data;
}

static QTemporaryFile *create_new_tempfile(const char *fileName){
  // create
  QFile source(fileName);
  QTemporaryFile *pdfile = create_temp_pdfile();

  // open
  printf("open: %d\n",pdfile->open());
  source.open(QIODevice::ReadOnly);

  printf("filename: -%s-\n",pdfile->fileName().ascii());

  // copy
  pdfile->write(source.readAll());

  // close
  pdfile->close();
  source.close();

  return pdfile;
}

static void *create_plugin_data(const SoundPluginType *plugin_type, struct SoundPlugin *plugin, hash_t *state, float sample_rate, int block_size){
  QTemporaryFile *pdfile;

  if (state==NULL)
    pdfile = create_new_tempfile((const char*)plugin_type->data);
  else
    pdfile = get_pdfile_from_state(state);

  Data *data = create_data(pdfile, plugin, sample_rate, block_size);

  if(state!=NULL)
    PD_recreate_controllers_from_state(plugin, state);

  return data;
}

static void cleanup_plugin_data(SoundPlugin *plugin){
  Data *data = (Data*)plugin->data;
  printf(">>>>>>>>>>>>>> Cleanup_plugin_data called for %p\n",plugin);

  libpds_closefile(data->pd, data->file);  
  libpds_delete(data->pd);

  PDGUI_clear(data->qtgui);

  delete data->pdfile;

  free(data);
}

static int get_effect_format(struct SoundPlugin *plugin, int effect_num){
  Data *data = (Data*)plugin->data;
  Pd_Controller *controller = &data->controllers[effect_num];

  return controller->type;
}

static const char *get_effect_name(struct SoundPlugin *plugin, int effect_num){
  static char notused_names[NUM_PD_CONTROLLERS][128];
  static bool inited=false;
  if(inited==false){
    int i;
    for(i=0;i<NUM_PD_CONTROLLERS;i++)
      sprintf(notused_names[i],"NOTUSED %d",i);
    inited=true;
  }

  Data *data = (Data*)plugin->data;
  Pd_Controller *controller = &data->controllers[effect_num];

  if (!strcmp(controller->name, ""))
    return notused_names[effect_num];
  else
    return controller->name;
}

void PD_set_qtgui(SoundPlugin *plugin, void *qtgui){
  Data *data = (Data*)plugin->data;
  data->qtgui = qtgui;
}

Pd_Controller *PD_get_controller(SoundPlugin *plugin, int n){
  Data *data = (Data*)plugin->data;
  return &data->controllers[n];
}

void PD_set_controller_name(SoundPlugin *plugin, int n, const char *name){
  Data *data = (Data*)plugin->data;
  Pd_Controller *controller = &data->controllers[n];

  if(!strcmp(controller->name, name))
    return;

  // Should check if it is different before binding. (but also if it is already binded)

  PLAYER_lock();{
    strncpy(controller->name, name, PD_NAME_LENGTH-1);

    if(controller->pd_binding != NULL)
      libpds_unbind(data->pd, controller->pd_binding);

    RT_bind_receiver(controller);

  }PLAYER_unlock();
}

void PD_recreate_controllers_from_state(SoundPlugin *plugin, hash_t *state){
  Data *data=(Data*)plugin->data;

  PDGUI_clear(data->qtgui);

  int i;
  for(i=0;i<NUM_PD_CONTROLLERS;i++) {
    Pd_Controller *controller = &data->controllers[i];

    if(controller->pd_binding!=NULL) {
      libpds_unbind(data->pd, controller->pd_binding);
      controller->pd_binding = NULL;
    }

    const char *name = HASH_has_key_at(state, "name", i) ? HASH_get_string_at(state, "name", i) : NULL;
    if(name==NULL || !strcmp(name,""))
      controller->name[0] = 0;
    else
      strncpy(controller->name, name, PD_NAME_LENGTH-1);

    controller->type      = HASH_get_int_at(state, "type", i);
    controller->min_value = HASH_get_float_at(state, "min_value", i);
    controller->value = HASH_get_float_at(state, "value", i);
    controller->max_value = HASH_get_float_at(state, "max_value", i);
    controller->has_gui   = HASH_get_int_at(state, "has_gui", i)==1 ? true : false;
    controller->config_dialog_visible = HASH_get_int_at(state, "config_dialog_visible", i)==1 ? true : false;

    if(controller->name != NULL) {
      RT_bind_receiver(controller);
    }
  }

  if(plugin->patch != NULL)
    GFX_update_instrument_widget(plugin->patch);
}

void PD_create_controllers_from_state(SoundPlugin *plugin, hash_t *state){
  Data *data=(Data*)plugin->data;

  int i;
  for(i=0;i<NUM_PD_CONTROLLERS;i++) {
    Pd_Controller *controller = &data->controllers[i];
    HASH_put_string_at(state, "name", i, controller->name);
    HASH_put_int_at(state, "type", i, controller->type);
    HASH_put_float_at(state, "min_value", i, controller->min_value);
    HASH_put_float_at(state, "value", i, controller->value);
    HASH_put_float_at(state, "max_value", i, controller->max_value);
    HASH_put_int_at(state, "has_gui", i, controller->has_gui ? 1 : 0);
    HASH_put_int_at(state, "config_dialog_visible", i, controller->config_dialog_visible ? 1 : 0);
  }
}

static void create_state(struct SoundPlugin *plugin, hash_t *state){
  printf("\n\n\n ********** CREATE_STATE ************* \n\n\n");
  Data *data = (Data*)plugin->data;

  PD_create_controllers_from_state(plugin, state);

  put_pdfile_into_state(data->pdfile, state);
}

// Warning! undo is created here (for simplicity). It's not common to call the undo creation function here, so beware of possible circular dependencies in the future.
void PD_delete_controller(SoundPlugin *plugin, int controller_num){
  Data *data=(Data*)plugin->data;

  Undo_PdControllers_CurrPos(plugin->patch);

  int i;
  hash_t *state = HASH_create(NUM_PD_CONTROLLERS);

  for(i=0;i<NUM_PD_CONTROLLERS-1;i++) {
    int s = i>=controller_num ? i+1 : i;
    Pd_Controller *controller = &data->controllers[s];
    HASH_put_string_at(state, "name", i, controller->name);
    HASH_put_int_at(state, "type", i, controller->type);
    HASH_put_float_at(state, "min_value", i, controller->min_value);
    HASH_put_float_at(state, "value", i, controller->value);
    HASH_put_float_at(state, "max_value", i, controller->max_value);
    HASH_put_int_at(state, "has_gui", i, controller->has_gui);
    HASH_put_int_at(state, "config_dialog_visible", i, controller->config_dialog_visible);
  }

  HASH_put_string_at(state, "name", NUM_PD_CONTROLLERS-1, "");
  HASH_put_int_at(state, "type", NUM_PD_CONTROLLERS-1, EFFECT_FORMAT_FLOAT);
  HASH_put_float_at(state, "min_value", NUM_PD_CONTROLLERS-1, 0.0);
  HASH_put_float_at(state, "value", NUM_PD_CONTROLLERS-1, 0.0);
  HASH_put_float_at(state, "max_value", NUM_PD_CONTROLLERS-1, 1.0);
  HASH_put_int_at(state, "has_gui", NUM_PD_CONTROLLERS-1, 0);
  HASH_put_int_at(state, "config_dialog_visible", i, 0);

  PD_recreate_controllers_from_state(plugin, state);
}


static void add_plugin(const char *name, const char *filename) {
  SoundPluginType *plugin_type = (SoundPluginType*)calloc(1,sizeof(SoundPluginType));

  plugin_type->type_name                = "Pd";
  plugin_type->name                     = strdup(name);
  plugin_type->info                     = "Pd is (mainly) made by Miller Puckette. Radium uses a modified version of libpd to access it.";
  plugin_type->num_inputs               = 2;
  plugin_type->num_outputs              = 2;
  plugin_type->is_instrument            = true;
  plugin_type->note_handling_is_RT      = false;
  plugin_type->num_effects              = NUM_PD_CONTROLLERS;
  plugin_type->get_effect_format        = get_effect_format;
  plugin_type->get_effect_name          = get_effect_name;
  plugin_type->effect_is_RT             = NULL;
  plugin_type->create_plugin_data       = create_plugin_data;
  plugin_type->cleanup_plugin_data      = cleanup_plugin_data;

  plugin_type->show_gui         = show_gui;
  plugin_type->hide_gui         = hide_gui;

  plugin_type->RT_process       = RT_process;
  plugin_type->play_note        = RT_play_note;
  plugin_type->set_note_volume  = RT_set_note_volume;
  plugin_type->stop_note        = RT_stop_note;
  plugin_type->set_effect_value = RT_set_effect_value;
  plugin_type->get_effect_value = RT_get_effect_value;
  plugin_type->get_display_value_string = get_display_value_string;

  //plugin_type->recreate_from_state = recreate_from_state;
  plugin_type->create_state        = create_state;

  plugin_type->data                = (void*)strdup(filename);

  //PR_add_menu_entry(PluginMenuEntry::normal(plugin_type));
  PR_add_plugin_type(plugin_type);
}

static void build_plugins(QDir dir){
  printf(">> dir: -%s-\n",dir.absolutePath().ascii());
  PR_add_menu_entry(PluginMenuEntry::level_up(dir.dirName()));

  dir.setSorting(QDir::Name);

  // browse dirs first.
  dir.setFilter(QDir::Dirs |  QDir::NoDotAndDotDot);

  {
    QFileInfoList list = dir.entryInfoList();
    
    for (int i = 0; i < list.size(); ++i) {
      QFileInfo fileInfo = list.at(i);
      //if(fileInfo.absoluteFilePath() != dir.absoluteFilePath())
        build_plugins(QDir(fileInfo.absoluteFilePath()));
    }
  }

    // Then the files
  dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
  {
    QFileInfoList list = dir.entryInfoList();
    
    for (int i = 0; i < list.size(); ++i) {
      QFileInfo fileInfo = list.at(i);
      printf("   file: -%s-\n",fileInfo.absoluteFilePath().ascii());
      if(fileInfo.suffix()=="pd")
        add_plugin(fileInfo.baseName().ascii(), fileInfo.absoluteFilePath().ascii());
    }
  }

  printf("<< dir: -%s-\n",dir.absolutePath().ascii());
  PR_add_menu_entry(PluginMenuEntry::level_down());
}

void create_pd_plugin(void){
  build_plugins(QDir(get_search_path()+OS_get_directory_separator()+"Pd"));
}

