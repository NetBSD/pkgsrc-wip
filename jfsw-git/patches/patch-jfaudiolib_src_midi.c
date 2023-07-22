$NetBSD$

alloca is in stdlib.h on NetBSD.

--- jfaudiolib/src/midi.c.orig	2023-03-21 20:06:34.000000000 +0000
+++ jfaudiolib/src/midi.c
@@ -34,8 +34,10 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <stdio.h>
 #ifdef _WIN32
 # include <malloc.h>
-#else
+#elseif defined(__linux)
 # include <alloca.h>
+#else
+# include <stdlib.h>
 #endif
 #include "sndcards.h"
 #include "drivers.h"
