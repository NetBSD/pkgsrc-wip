$NetBSD$

--- 3rdparty/hts_engine_API/lib/HTS_misc.c.orig	2015-02-15 20:01:07.000000000 +0000
+++ 3rdparty/hts_engine_API/lib/HTS_misc.c
@@ -247,6 +247,8 @@ size_t HTS_ftell(HTS_File * fp)
       fgetpos((FILE *) fp->pointer, &pos);
 #if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__)
       return (size_t) pos;
+#elif defined(__NetBSD__)
+      return (size_t) pos._pos;
 #else
       return (size_t) pos.__pos;
 #endif                          /* _WIN32 || __CYGWIN__ || __APPLE__ || __ANDROID__ */
