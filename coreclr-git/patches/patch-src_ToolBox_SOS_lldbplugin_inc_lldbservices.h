$NetBSD$

--- src/ToolBox/SOS/lldbplugin/inc/lldbservices.h.orig	2016-02-27 21:09:29.680763122 +0000
+++ src/ToolBox/SOS/lldbplugin/inc/lldbservices.h
@@ -11,6 +11,8 @@
 #ifndef __LLDBSERVICES_H__
 #define __LLDBSERVICES_H__
 
+#include <stdarg.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
