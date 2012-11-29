$NetBSD: patch-src_debug.h,v 1.1 2012/11/29 14:22:55 ryo-on Exp $

* Fix recent gcc build from Arch Linux

--- src/debug.h.orig	2006-02-14 04:57:01.000000000 +0000
+++ src/debug.h
@@ -5,7 +5,7 @@
 #include <assert.h>
 #include <stdio.h>
 #include <string>
-
+#include <cstdlib>
 
 namespace audiere {
 
