$NetBSD: patch-include_zbar_Exception.h,v 1.1 2015/07/07 17:16:35 leot1990 Exp $

Add <cstddef> (needed for NULL).

--- include/zbar/Exception.h.orig	2009-10-23 18:16:44.000000000 +0000
+++ include/zbar/Exception.h
@@ -30,6 +30,7 @@
 # error "include zbar.h in your application, **not** zbar/Exception.h"
 #endif
 
+#include <cstddef>
 #include <exception>
 #include <new>
 
