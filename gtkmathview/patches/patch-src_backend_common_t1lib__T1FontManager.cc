$NetBSD: patch-src_backend_common_t1lib__T1FontManager.cc,v 1.1 2015/03/04 13:54:26 nros Exp $
getenv needs cstdlib
--- src/backend/common/t1lib_T1FontManager.cc.orig	2007-08-17 10:02:44.000000000 +0000
+++ src/backend/common/t1lib_T1FontManager.cc
@@ -18,6 +18,7 @@
 
 #include <config.h>
 
+#include <cstdlib>
 #include <t1lib.h>
 
 #include "AbstractLogger.hh"
