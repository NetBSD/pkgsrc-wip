$NetBSD: patch-src_db.h,v 1.1 2014/09/22 11:20:28 othyro Exp $

Use pkgsrc databases/db4.

--- src/db.h.orig	2014-06-13 21:36:21.000000000 +0000
+++ src/db.h
@@ -11,7 +11,7 @@
 #include <string>
 #include <vector>
 
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CAddress;
 class CAddrMan;
