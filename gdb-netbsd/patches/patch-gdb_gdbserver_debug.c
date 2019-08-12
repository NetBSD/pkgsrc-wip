$NetBSD$

--- gdb/gdbserver/debug.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbserver/debug.c
@@ -20,7 +20,7 @@
 #include <chrono>
 
 #if !defined (IN_PROCESS_AGENT)
-int remote_debug = 0;
+int remote_debug = 1;
 #endif
 
 /* Output file for debugging.  Default to standard error.  */
@@ -28,7 +28,7 @@ FILE *debug_file = stderr;
 
 /* Enable miscellaneous debugging output.  The name is historical - it
    was originally used to debug LinuxThreads support.  */
-int debug_threads;
+int debug_threads = 1;
 
 /* Include timestamps in debugging output.  */
 int debug_timestamp;
