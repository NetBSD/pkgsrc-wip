$NetBSD: patch-src_include_utils_palloc.h,v 1.1 2015/04/13 19:59:59 fhajny Exp $

Fix build on SunOS.
--- src/include/utils/palloc.h.orig	2015-04-08 07:28:03.000000000 +0000
+++ src/include/utils/palloc.h
@@ -28,6 +28,7 @@
 #ifndef PALLOC_H
 #define PALLOC_H
 
+#include <stdarg.h>
 #include "pg_config_manual.h"
 
 /*
