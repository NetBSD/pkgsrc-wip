$NetBSD$

Use fseeko and ftello on NetBSD as well,

--- GsKit/base/utils/property_tree/tinyxml2.cpp.orig	2021-04-11 19:10:59.000000000 +0000
+++ GsKit/base/utils/property_tree/tinyxml2.cpp
@@ -103,7 +103,7 @@ distribution.
 #if defined(_WIN64)
 	#define TIXML_FSEEK _fseeki64
 	#define TIXML_FTELL _ftelli64
-#elif defined(__APPLE__) || (__FreeBSD__)
+#elif defined(__APPLE__) || (__FreeBSD__) || defined(__NetBSD__)
 	#define TIXML_FSEEK fseeko
 	#define TIXML_FTELL ftello
 #elif defined(ANDROID)
