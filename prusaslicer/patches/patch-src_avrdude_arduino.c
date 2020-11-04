$NetBSD$

alloca requires stdlib.h.

--- src/avrdude/arduino.c.orig	2020-03-21 10:55:51.000000000 +0000
+++ src/avrdude/arduino.c
@@ -28,6 +28,7 @@
 #include "ac_cfg.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
