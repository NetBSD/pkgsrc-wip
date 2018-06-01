$NetBSD$

--- lib/asan/asan_rtl.cc.orig	2018-06-01 09:39:33.000000000 +0000
+++ lib/asan/asan_rtl.cc
@@ -384,6 +384,7 @@ static void AsanInitInternal() {
   asan_init_is_running = true;
 
   CacheBinaryName();
+  CheckASLR();
 
   // Initialize flags. This must be done early, because most of the
   // initialization steps look at flags().
