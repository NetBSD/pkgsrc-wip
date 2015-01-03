$NetBSD: patch-src_openfiles.cpp,v 1.1 2015/01/03 04:23:01 obache Exp $

* workaround for missing NI_IDN support.

--- src/openfiles.cpp.orig	2014-01-25 16:04:53.000000000 +0000
+++ src/openfiles.cpp
@@ -15,6 +15,10 @@
 #include "util.h"
 #include "settings-keys.h"
 
+#ifndef NI_IDN
+#define NI_IDN 0
+#endif
+
 enum
 {
 	COL_FD,
