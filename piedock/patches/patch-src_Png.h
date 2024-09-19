$NetBSD: patch-src_Png.h,v 1.1 2013/02/16 11:16:33 thomasklausner Exp $

Fix build with png-1.6.

--- src/Png.h.orig	2012-06-19 21:12:46.000000000 +0000
+++ src/Png.h
@@ -19,6 +19,7 @@
 #include <istream>
 #include <ostream>
 #include <string>
+#include <string.h>
 #include <png.h>
 
 namespace PieDock
