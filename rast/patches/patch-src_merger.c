$NetBSD: patch-src_merger.c,v 1.1.1.1 2011/02/21 11:36:58 obache Exp $

* fixes for standard C style.

--- src/merger.c.orig	2005-09-12 08:23:05.000000000 +0000
+++ src/merger.c
@@ -48,6 +48,7 @@ rast_merger_open(rast_db_t **base,
         }
     }
 
+    {
     rast_merger_t *db = (rast_merger_t *)
         apr_palloc(pool, sizeof(rast_merger_t));
     *base = (rast_db_t *) db;
@@ -58,6 +59,7 @@ rast_merger_open(rast_db_t **base,
     db->merged_dbs = merge_dbs;
     db->properties = NULL;
     db->num_properties = 0;
+    }
     return RAST_OK;
 }
 
