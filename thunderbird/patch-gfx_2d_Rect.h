$NetBSD$

GCC 13 fixes.

--- gfx/2d/Rect.h.orig	2023-05-12 14:17:38.303449723 +0200
+++ gfx/2d/Rect.h	2023-05-12 14:18:04.645202892 +0200
@@ -15,6 +15,7 @@
 #include "mozilla/Maybe.h"
 
 #include <cmath>
+#include <cstdint>
 
 namespace mozilla {
 
