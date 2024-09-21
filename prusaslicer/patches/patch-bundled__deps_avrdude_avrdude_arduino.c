$NetBSD$

alloca requires stdlib.h.

--- bundled_deps/avrdude/avrdude/arduino.c.orig	2024-09-20 23:45:57.762961668 +0000
+++ bundled_deps/avrdude/avrdude/arduino.c
@@ -28,6 +28,7 @@
 #include "ac_cfg.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
