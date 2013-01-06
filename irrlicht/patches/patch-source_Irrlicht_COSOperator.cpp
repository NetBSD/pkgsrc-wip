$NetBSD: patch-source_Irrlicht_COSOperator.cpp,v 1.1 2013/01/06 14:13:27 ryo-on Exp $

--- source/Irrlicht/COSOperator.cpp.orig	Sun Jan  6 13:20:50 2013
+++ source/Irrlicht/COSOperator.cpp
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <unistd.h>
 #ifndef _IRR_SOLARIS_PLATFORM_
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
