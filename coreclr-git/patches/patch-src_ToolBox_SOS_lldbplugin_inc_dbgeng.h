$NetBSD$

--- src/ToolBox/SOS/lldbplugin/inc/dbgeng.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/lldbplugin/inc/dbgeng.h
@@ -11,6 +11,8 @@
 #ifndef __DBGENG_H__
 #define __DBGENG_H__
 
+#include <cstdarg>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
