$NetBSD$

--- base/trace_event/process_memory_dump.h.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/trace_event/process_memory_dump.h
@@ -23,7 +23,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if (defined(OS_POSIX) && !defined(OS_NACL)) || defined(OS_WIN)
+#if (defined(OS_POSIX) && !defined(OS_NACL) && !defined(OS_BSD)) || defined(OS_WIN)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
