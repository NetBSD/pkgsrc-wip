$NetBSD: patch-src_audiere.h,v 1.1 2012/11/29 14:22:55 ryo-on Exp $

* Fix recent gcc build from Arch Linux

--- src/audiere.h.orig	2006-02-14 04:57:01.000000000 +0000
+++ src/audiere.h
@@ -28,6 +28,7 @@
 
 #include <vector>
 #include <string>
+#include <cstring>
 
 #ifdef _MSC_VER
 #pragma warning(disable : 4786)
