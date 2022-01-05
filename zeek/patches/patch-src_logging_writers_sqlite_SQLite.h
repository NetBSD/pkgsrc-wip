$NetBSD$

Use pkgsrc sqlite3

--- src/logging/writers/sqlite/SQLite.h.orig	2021-09-22 16:48:15.000000000 +0000
+++ src/logging/writers/sqlite/SQLite.h
@@ -8,7 +8,7 @@
 
 #include "zeek/logging/WriterBackend.h"
 #include "zeek/threading/formatters/Ascii.h"
-#include "zeek/3rdparty/sqlite3.h"
+#include <sqlite3.h>
 #include "zeek/Desc.h"
 
 namespace zeek::logging::writer::detail {
