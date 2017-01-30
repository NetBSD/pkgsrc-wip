--- ./source/darkplaces/makefile.inc.orig	2015-08-25 15:10:24.000000000 -0700
+++ ./source/darkplaces/makefile.inc	2017-01-29 21:11:21.384400446 -0800
@@ -30,9 +30,9 @@
 SDLCONFIG_UNIXCFLAGS?=`$(SDL_CONFIG) --cflags`
 SDLCONFIG_UNIXCFLAGS_X11?=
 SDLCONFIG_UNIXLIBS?=`$(SDL_CONFIG) --libs`
-SDLCONFIG_UNIXLIBS_X11?=-lX11
+SDLCONFIG_UNIXLIBS_X11?=
 SDLCONFIG_UNIXSTATICLIBS?=`$(SDL_CONFIG) --static-libs`
-SDLCONFIG_UNIXSTATICLIBS_X11?=-lX11
+SDLCONFIG_UNIXSTATICLIBS_X11?=
 SDLCONFIG_MACOSXCFLAGS=-I/Library/Frameworks/SDL.framework/Headers -I$(HOME)/Library/Frameworks/SDL.framework/Headers
 SDLCONFIG_MACOSXLIBS=-F$(HOME)/Library/Frameworks/ -framework SDL -framework Cocoa $(SDLCONFIG_MACOSXCFLAGS)
 SDLCONFIG_MACOSXSTATICLIBS=-F$(HOME)/Library/Frameworks/ -framework SDL -framework Cocoa $(SDLCONFIG_MACOSXCFLAGS)
@@ -205,7 +205,7 @@
 
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o thread_pthread.o keysym2ucs.o $(OBJ_MENU) $(OBJ_SOUND) $(OBJ_CD) $(OBJ_VIDEO_CAPTURE) $(OBJ_COMMON)
 
-LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
+LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL) -L$(PREFIX)/lib -Wl,-rpath,/usr/X11R7/lib
 LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86vm -pthread $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl
 LDFLAGS_UNIXSV_PRELOAD=-lz -ljpeg -lpng -lcurl
