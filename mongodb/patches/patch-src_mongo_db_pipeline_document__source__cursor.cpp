$NetBSD: patch-src_mongo_db_pipeline_document__source__cursor.cpp,v 1.1 2014/04/10 11:46:42 fhajny Exp $

Fix C++11 support.
--- src/mongo/db/pipeline/document_source_cursor.cpp.orig	2014-04-07 00:36:57.000000000 +0000
+++ src/mongo/db/pipeline/document_source_cursor.cpp
@@ -141,7 +141,7 @@ namespace mongo {
 
         if (!_limit) {
             _limit = dynamic_cast<DocumentSourceLimit*>(nextSource.get());
-            return _limit; // false if next is not a $limit
+            return _limit != NULL; // false if next is not a $limit
         }
         else {
             return _limit->coalesce(nextSource);
