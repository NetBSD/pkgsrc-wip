$NetBSD$

Use pkgsrc sqlite3

--- src/input/readers/sqlite/SQLite.h.orig	2021-09-22 16:48:15.000000000 +0000
+++ src/input/readers/sqlite/SQLite.h
@@ -6,7 +6,7 @@
 
 #include <iostream>
 #include <vector>
-#include "zeek/3rdparty/sqlite3.h"
+#include <sqlite3.h>
 
 #include "zeek/input/ReaderBackend.h"
 #include "zeek/threading/formatters/Ascii.h"
