$NetBSD: patch-xbmc_addons_Addon.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/addons/Addon.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/addons/Addon.cpp
@@ -47,7 +47,7 @@
 #if defined(TARGET_DARWIN)
 #include "../platform/darwin/OSXGNUReplacements.h"
 #endif
-#ifdef TARGET_FREEBSD
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include "freebsd/FreeBSDGNUReplacements.h"
 #endif
 
