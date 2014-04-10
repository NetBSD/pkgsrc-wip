$NetBSD: patch-src_mongo_db_pipeline_document__source__sort.cpp,v 1.1 2014/04/10 11:46:42 fhajny Exp $

Fix C++11 support.
--- src/mongo/db/pipeline/document_source_sort.cpp.orig	2014-04-07 00:36:57.000000000 +0000
+++ src/mongo/db/pipeline/document_source_sort.cpp
@@ -92,7 +92,7 @@ namespace mongo {
     bool DocumentSourceSort::coalesce(const intrusive_ptr<DocumentSource> &pNextSource) {
         if (!limitSrc) {
             limitSrc = dynamic_cast<DocumentSourceLimit*>(pNextSource.get());
-            return limitSrc; // false if next is not a $limit
+            return limitSrc != NULL; // false if next is not a $limit
         }
         else {
             return limitSrc->coalesce(pNextSource);
