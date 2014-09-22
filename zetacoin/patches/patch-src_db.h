$NetBSD: patch-src_db.h,v 1.1 2014/09/22 11:23:59 othyro Exp $

Use pkgsrc databases/db4.

--- src/db.h.orig	2014-06-19 07:51:15.000000000 +0000
+++ src/db.h
@@ -15,7 +15,7 @@
 #include <vector>
 
 #include <boost/filesystem/path.hpp>
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CAddrMan;
 struct CBlockLocator;
