$NetBSD$

--- lib/msan/msan.cc.orig	2018-02-27 02:50:00.000000000 +0000
+++ lib/msan/msan.cc
@@ -397,6 +397,7 @@ void __msan_init() {
   InitTlsSize();
 
   CacheBinaryName();
+  CheckASLR();
   InitializeFlags();
 
   // Install tool-specific callbacks in sanitizer_common.
