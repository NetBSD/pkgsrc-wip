$NetBSD: patch-src_db.h,v 1.1 2013/12/12 20:45:11 noud4 Exp $

Use pkgsrc databases/db4.

--- src/db.h.orig	2013-09-12 10:43:31.000000000 +0000
+++ src/db.h
@@ -11,7 +11,7 @@
 #include <string>
 #include <vector>
 
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CAddress;
 class CAddrMan;
