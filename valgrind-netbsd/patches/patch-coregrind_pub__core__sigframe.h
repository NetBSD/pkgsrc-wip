$NetBSD$

--- coregrind/pub_core_sigframe.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/pub_core_sigframe.h
@@ -60,8 +60,13 @@ void VG_(sigframe_create) ( ThreadId tid
 
 /* Remove a signal frame from thread 'tid's stack, and 
    restore the CPU state from it. */
+#ifdef VGO_netbsd
+extern
+void VG_(sigframe_destroy)( ThreadId tid );
+#else
 extern 
 void VG_(sigframe_destroy)( ThreadId tid, Bool isRT );
+#endif
 
 #if defined(VGO_solaris)
 extern
