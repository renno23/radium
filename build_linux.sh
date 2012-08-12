#!/bin/sh

export PYTHONEXE=`which python2`
export MOC=moc
export UIC=uic 

export BUILDTYPE=RELEASE
export OPTIMIZE="-mtune=native -O3"

export CCC=g++
export CC=gcc
export LINKER=g++

export PKG=pkg-config
export PYPATH=`$PYTHONEXE -c "import sys;print sys.prefix+'/include/python'+sys.version[:3]"`

export QT_CFLAGS=`$PKG --cflags Qt3Support`
export QT_LDFLAGS=`$PKG --libs Qt3Support`

export RTMIDI_CFLAGS="-D__UNIX_JACK__ -D__LINUX_ALSA__  -D__RTMIDI_DEBUG__"
export RTMIDI_LDFLAGS="-lpthread -lasound -ljack"

export OS_OPTS=

PYTHONLIBPATH=`$PYTHONEXE -c "import sys;print '-L'+sys.prefix+'/lib'"`
PYTHONLIBNAME=`$PYTHONEXE -c "import sys;print '-lpython'+sys.version[:3]"`
export OS_LDFLAGS="-pthread bin/packages/gc-7.2/.libs/libgc.a $PYTHONLIBPATH $PYTHONLIBNAME -fPIC"


make radium $@