$NetBSD$

--- src/headers/paristio.h.orig	2014-09-15 11:32:55.000000000 +0000
+++ src/headers/paristio.h
@@ -13,6 +13,8 @@ Foundation, Inc., 51 Franklin Street, Fi
 
 /* This file contains memory and I/O management definitions       */
 
+#include <fcntl.h>
+
 typedef struct {
   long s, us;
 } pari_timer;
