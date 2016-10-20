$NetBSD$

Use pkgsrc databases/db4.

--- src/db.h.orig	2015-09-28 15:49:30.000000000 +0000
+++ src/db.h
@@ -18,7 +18,7 @@
 
 #include <boost/filesystem/path.hpp>
 
-#include <db_cxx.h>
+#include <db4/db_cxx.h>
 
 class CDiskBlockIndex;
 class COutPoint;
