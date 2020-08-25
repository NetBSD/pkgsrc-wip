$NetBSD$

--- gdbserver/debug.cc.orig	2020-08-18 00:00:07.000000000 +0000
+++ gdbserver/debug.cc
@@ -20,14 +20,14 @@
 #include <chrono>
 
 #if !defined (IN_PROCESS_AGENT)
-int remote_debug = 0;
+int remote_debug = 1;
 #endif
 
 /* Output file for debugging.  Default to standard error.  */
 FILE *debug_file = stderr;
 
 /* See debug.h.  */
-int debug_threads;
+int debug_threads = 1;
 
 /* Include timestamps in debugging output.  */
 int debug_timestamp;
