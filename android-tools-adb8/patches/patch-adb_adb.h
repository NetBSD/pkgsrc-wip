$NetBSD$

--- adb/adb.h.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/adb.h
@@ -201,9 +201,7 @@ ConnectionState connection_state(atransp
 
 extern const char* adb_device_banner;
 
-#if !ADB_HOST
 extern int SHELL_EXIT_NOTIFY_FD;
-#endif // !ADB_HOST
 
 #define CHUNK_SIZE (64*1024)
 
