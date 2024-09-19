$NetBSD$

--- /usr/pkgsrc/multimedia/kodi/work/xbmc-xbmc-147cec4/xbmc/cores/DllLoader/coffldr.h.orig	2017-05-24 20:49:32.000000000 +0000
+++ /usr/pkgsrc/multimedia/kodi/work/xbmc-xbmc-147cec4/xbmc/cores/DllLoader/coffldr.h
@@ -25,21 +25,6 @@
 
 #include <stdio.h>
 
-#ifndef _FILE_DEFINED
-struct _iobuf {
-        char *_ptr;
-        int   _cnt;
-        char *_base;
-        int   _flag;
-        int   _file;
-        int   _charbuf;
-        int   _bufsiz;
-        char *_tmpfname;
-        };
-typedef struct _iobuf FILE;
-#define _FILE_DEFINED
-#endif
-
 class CoffLoader
 {
 public:
