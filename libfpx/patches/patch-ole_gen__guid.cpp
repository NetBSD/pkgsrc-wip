$NetBSD$
* __unix is not defined on NetBSD, _UNIX is always defined by the build system
--- ole/gen_guid.cpp.orig	2013-09-02 15:45:00.000000000 +0000
+++ ole/gen_guid.cpp
@@ -65,7 +65,7 @@ typedef struct _timespec
 //  Internal Functions
 //  ----------------------------------------------------------------------------
 
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
 static void GetENETAddress(unsigned char *ENETaddress)
 {
   // MPPParamBlock thePB;
