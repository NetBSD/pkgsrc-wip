$NetBSD$

--- include/lldb/Host/linux/Personality.h.orig	2016-12-14 14:10:24.000000000 +0000
+++ include/lldb/Host/linux/Personality.h
@@ -12,6 +12,7 @@
 #ifndef liblldb_Host_linux_Personality_h_
 #define liblldb_Host_linux_Personality_h_
 
+#if !defined(__NetBSD__)
 #ifdef __ANDROID__
 #include <android/api-level.h>
 #endif
@@ -21,5 +22,6 @@
 #else
 #include <sys/personality.h>
 #endif
+#endif
 
 #endif // liblldb_Host_linux_Personality_h_
