$NetBSD$

--- CodeLite/tags_storage_sqlite3.h	2022-05-03 22:38:34.770034020 +0300
+++ CodeLite/tags_storage_sqlite3.h
@@ -25,6 +25,8 @@
 #ifndef CODELITE_TAGS_DATABASE_H
 #define CODELITE_TAGS_DATABASE_H
 
+#include <wx/filename.h>
+
 #include "codelite_exports.h"
 #include "entry.h"
 #include "fileentry.h"
@@ -33,7 +35,6 @@
 #include "wxStringHash.h"
 
 #include <unordered_map>
-#include <wx/filename.h>
 #include <wx/wxsqlite3.h>
 
 /**
