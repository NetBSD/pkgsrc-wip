$NetBSD$

Remove alloca.h, it's an obsolete header.

--- svcore/plugin/DSSIPluginInstance.cpp.orig	2015-10-22 11:26:02.000000000 +0000
+++ svcore/plugin/DSSIPluginInstance.cpp
@@ -28,7 +28,6 @@
 #include <cstdlib>
 
 #ifndef Q_OS_WIN32
-#include <alloca.h>
 #else
 #include <memory.h>
 #endif
