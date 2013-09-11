$NetBSD: patch-percol_finder.py,v 1.1 2013/09/11 05:10:05 phonohawk Exp $

Do not hard-code the PREFIX.

--- percol/finder.py.orig	2013-09-11 03:40:47.000000000 +0000
+++ percol/finder.py
@@ -204,7 +204,7 @@ class FinderMultiQueryMigemo(FinderMulti
     def get_name(self):
         return "migemo"
 
-    dictionary_path = "/usr/local/share/migemo/utf-8/migemo-dict"
+    dictionary_path = "@PREFIX@/share/migemo/utf-8/migemo-dict"
     minimum_query_length = 2
 
     migemo_instance = None
