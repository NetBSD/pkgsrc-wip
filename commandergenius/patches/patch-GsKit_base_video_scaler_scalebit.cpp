$NetBSD: patch-lib_GsKit_base_video_scaler_scalebit.cpp,v 1.1 2015/08/19 21:21:53 yhardy Exp $

Use malloc.h on NetBSD, not alloca.h.

--- ./GsKit/base/video/scaler/scalebit.cpp.orig	2014-05-10 15:16:02.000000000 +0000
+++ ./GsKit/base/video/scaler/scalebit.cpp
@@ -42,6 +42,8 @@
 
 #ifdef __MINGW32__
 	#include <malloc.h>
+#elif defined(__NetBSD__)
+	#include <malloc.h>
 #else
 	#include <alloca.h>
 #endif
