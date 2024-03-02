$NetBSD$

* Fix build on NetBSD, missing AI_V4MAPPED

--- sdk/src/http.cpp.orig	2023-06-20 16:04:22.829147987 +0000
+++ sdk/src/http.cpp
@@ -270,7 +270,7 @@ void HttpIO::getMEGADNSservers(string *d
         hints.ai_family = AF_UNSPEC;
 
 #ifndef __MINGW32__
-        hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+        hints.ai_flags = AI_ADDRCONFIG;
 #endif
 
         if (!getaddrinfo("ns.mega.co.nz", NULL, &hints, &aiList))
