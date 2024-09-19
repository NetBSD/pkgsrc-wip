$NetBSD$

Use pkgsrc databases/db4.

--- src/db.h.orig	2015-03-24 01:40:33.000000000 +0000
+++ src/db.h
@@ -15,7 +15,7 @@
 #include <vector>
 
 #include <boost/filesystem/path.hpp>
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CAddrMan;
 struct CBlockLocator;
