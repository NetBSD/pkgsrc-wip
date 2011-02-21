$NetBSD: patch-src_local__db.c,v 1.1.1.1 2011/02/21 11:36:58 obache Exp $

* Fixes macro usage

--- src/local_db.c.orig	2005-09-15 10:02:24.000000000 +0000
+++ src/local_db.c
@@ -2111,7 +2111,7 @@ create_result_items(doc_data_t **docs, i
 
             encoding_module = docs[i]->db->encoding_module;
             tf = APR_RING_FIRST(docs[i]->terms);
-            if (tf == APR_RING_SENTINEL(&docs[i]->terms,
+            if (tf == APR_RING_SENTINEL(docs[i]->terms,
                                         rast_term_frequency_t, link)) {
                 error = get_summary(pool, encoding_module,
                                     summary, summary_nbytes,
