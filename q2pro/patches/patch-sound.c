--- src/unix/sound.c	2018-12-28 14:34:51.000000000 +0100
+++ src/unix/sound.c	2019-03-08 13:51:27.435968350 +0100
@@ -23,7 +23,7 @@
 #include "shared/shared.h"
 #include "common/zone.h"
 #include "client/sound/dma.h"
-#include <SDL.h>
+#include <SDL2/SDL.h>
 
 static void Filler(void *userdata, Uint8 *stream, int len)
 {
