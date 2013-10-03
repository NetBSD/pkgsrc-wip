$NetBSD: patch-libtest__lite.h,v 1.2 2013/10/03 00:44:55 genolopolis Exp $
alloca.h is a linux-ism

--- libtest/lite.h-orig	2013-10-02 18:39:21.000000000 +0000
+++ libtest/lite.h
@@ -51,7 +51,7 @@
 # include <string.h>
 #endif
 
-#if defined(WIN32)
+#if defined(WIN32) || defined(__NetBSD__)
 # include <malloc.h>
 #else
 # include <alloca.h>
