$NetBSD$

--- src/db.h.orig	2015-05-31 10:15:00.000000000 +0000
+++ src/db.h
@@ -15,7 +15,7 @@
 #include <vector>
 
 #include <boost/filesystem/path.hpp>
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CAddrMan;
 struct CBlockLocator;
