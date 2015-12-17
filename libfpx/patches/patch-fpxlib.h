$NetBSD$
* Don't use autoconf config file in public header,
  it's macros are unused in it and the macros might conflict
  with packages own config.h
--- fpxlib.h.orig	2015-12-11 19:33:16.000000000 +0000
+++ fpxlib.h
@@ -11,7 +11,6 @@
 #ifdef __cplusplus
 extern "C" {
 #endif
-#include "fpxlib-config.h"
 #include <inttypes.h>
 
   typedef struct IStream IStream;
