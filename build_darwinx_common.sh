#!/bin/bash

set -e

export PYTHONEXE=python #In Mingw, this is just the python we use to autogenerate files and so forth during the build process, it is not used to find header or link files
export MOC=moc-qt4
export UIC=uic-qt4

export OPTIMIZE="-O3"

#export CCC="darwinx-g++ -arch i386 -arch ppc -arch x86_64"
#export CC="darwinx-gcc -arch i386 -arch ppc -arch x86_64"
#export LINKER="darwinx-g++ -arch i386 -arch ppc -arch x86_64"

export CCC="darwinx-g++ -arch i386 -arch x86_64"
export CC="darwinx-gcc -arch i386 -arch x86_64"
export LINKER="darwinx-g++ -arch i386 -arch x86_64"

#export BUILDTYPE=DEBUG
export BUILDTYPE=RELEASE

export PYPATH=/home/kjetil/radium-qt4/darwinx/Versions/Current/include/python2.7

export QT_CFLAGS="`darwinx-pkg-config --cflags Qt3Support`"
export QT_LDFLAGS="`darwinx-pkg-config --libs Qt3Support`"

export OS_OPTS="-DFOR_MACOSX"
#export OS_LDFLAGS="`pwd`/darwinx/gc-7.2/.libs/libgc.a `pwd`/darwinx/Versions/2.7/lib/python2.7/config/libpython2.7.a -lpthread -framework Carbon -framework Foundation"
export OS_LDFLAGS="`pwd`/darwinx/gc-7.2/.libs/libgc.a -L`pwd`/darwinx/Versions/2.7/lib/ -lpython2.7 -lpthread -framework Carbon -framework Foundation"

export RTMIDI_CFLAGS=" -D__MACOSX_CORE__ -D__RTMIDI_DEBUG__"
export RTMIDI_LDFLAGS="-framework CoreMIDI -framework CoreAudio"

if [ $BUILDTYPE = "RELEASE" ] ; then
    export OS_LDFLAGS="$OS_LDFLAGS"
fi

export OBJ_X11=
export OBJ_WIN=

# To build gc for mingw32:
#
# cd bin/packages/gc-7.2
# mingw32-configure
# echo "void RADIUM_ensure_bin_packages_gc_is_used(void){}" >>malloc.c
# mingw32-make
# (that's it)

darwinx-make radium $@

./darwinx_change_qt_path.sh bin/radium
darwinx-install_name_tool -change /Library/Frameworks/Python.framework/Versions/2.7/Python @executable_path/python2.7/libpython2.7.dylib bin/radium

darwinx-otool -L bin/radium

cp bin/radium Dropbox/radium.app/Contents/MacOS/

echo "compilation finished"


#cp bin/radium mingw/radium/radium.exe
#cp bin/radium temp/bin/radium.exe
