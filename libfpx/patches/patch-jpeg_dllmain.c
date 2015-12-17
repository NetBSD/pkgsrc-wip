$NetBSD$
* __unix is not defined on NetBSD, _UNIX is always defined by the build system
--- jpeg/dllmain.c.orig	2013-09-02 15:45:00.000000000 +0000
+++ jpeg/dllmain.c
@@ -3,7 +3,7 @@ Description:  Main module for dllJPEG li
 */ 
 
 
-#ifndef __unix
+#ifndef _UNIX
 #include <windows.h>
 #include "jpegconf.h"
 
