$NetBSD$

AI_ALL flag is not currently implemented on NetBSD.

--- dlls/ws2_32/unixlib.c.orig	2022-01-18 20:52:35.000000000 +0000
+++ dlls/ws2_32/unixlib.c
@@ -120,7 +120,9 @@ static const int addrinfo_flag_map[][2] 
 #ifdef AI_V4MAPPED
     MAP( AI_V4MAPPED ),
 #endif
+#ifdef AI_ALL
     MAP( AI_ALL ),
+#endif
     MAP( AI_ADDRCONFIG ),
 };
 
