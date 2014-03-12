$NetBSD: patch-src_include_logsupport.h,v 1.1 2014/03/12 02:08:35 makoto Exp $

Fix a header guard to reduce warnings.

--- src/include/logsupport.h.orig	2013-09-17 19:27:33.000000000 +0000
+++ src/include/logsupport.h
@@ -1,5 +1,5 @@
 #ifndef SUPPORT_H
-#define SUPPORT_h
+#define SUPPORT_H
 
 #include <string>
 
