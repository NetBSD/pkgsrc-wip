--- ./source/darkplaces/makefile.inc.old	2017-01-29 16:01:20.020748344 -0800
+++ ./source/darkplaces/makefile.inc	2017-01-29 16:01:52.502349209 -0800
@@ -205,7 +205,7 @@
 
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o thread_pthread.o keysym2ucs.o $(OBJ_MENU) $(OBJ_SOUND) $(OBJ_CD) $(OBJ_VIDEO_CAPTURE) $(OBJ_COMMON)
 
-LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
+LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_Z) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL) -L${PREFIX}/lib
 LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86vm -pthread $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl
 LDFLAGS_UNIXSV_PRELOAD=-lz -ljpeg -lpng -lcurl
