$NetBSD$

Refer to the system's jansson.h header, instead of the one included
with zero-epwing.

--- book.c.orig	2017-10-05 21:42:21.000000000 +0000
+++ book.c
@@ -28,7 +28,8 @@
 #include "eb/eb/text.h"
 #include "eb/eb/error.h"
 
-#include "jansson/include/jansson.h"
+//#include "jansson/include/jansson.h"
+#include <jansson.h>
 
 /*
  * Local types
