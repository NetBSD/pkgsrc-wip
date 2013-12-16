$NetBSD: patch-src_main.cpp,v 1.1 2013/12/16 07:54:18 nsloss Exp $

get_current_dir_name() is not found on NetBSD.

--- src/main.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/main.cpp
@@ -28,6 +28,9 @@
 #endif
 #include "compat.h"
 
+#ifdef __NetBSD__
+#define get_current_dir_name() getcwd(NULL, PATH_MAX)
+#endif
 
 using namespace std;
 using namespace lightspark;
