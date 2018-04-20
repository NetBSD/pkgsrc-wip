$NetBSD$

Need sys/stat.h for mkdir.
Use the unix methods for !WIN32

--- src/engine/unzip/miniunz.c.orig	2018-04-14 07:26:16.000000000 +0000
+++ src/engine/unzip/miniunz.c
@@ -45,6 +45,7 @@
 #include <time.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/stat.h>
 
 #ifdef _WIN32
 # include <direct.h>
@@ -97,7 +98,6 @@ void change_file_date(filename,dosdate,t
   SetFileTime(hFile,&ftm,&ftLastAcc,&ftm);
   CloseHandle(hFile);
 #else
-#if defined(linux) || defined(__APPLE__)
   struct utimbuf ut;
   struct tm newdate;
   newdate.tm_sec = tmu_date.tm_sec;
@@ -114,7 +114,6 @@ void change_file_date(filename,dosdate,t
   ut.actime=ut.modtime=mktime(&newdate);
   utime(filename,&ut);
 #endif
-#endif
 }
 
 
@@ -127,13 +126,7 @@ int mymkdir(dirname)
     int ret=0;
 #if defined(WIN32) || defined(_WIN32)
     ret = _mkdir(dirname);
-#endif
-
-#if defined(__linux__) || __linux__
-    ret = mkdir (dirname,0775);
-#endif
-
-#if defined(__APPLE__)
+#else
     ret = mkdir (dirname,0775);
 #endif
     return ret;
