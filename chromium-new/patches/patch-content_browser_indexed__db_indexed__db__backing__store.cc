$NetBSD$

--- content/browser/indexed_db/indexed_db_backing_store.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/indexed_db/indexed_db_backing_store.cc
@@ -2422,7 +2422,7 @@ bool IndexedDBBackingStore::WriteBlobFil
         // The round-trip can be lossy; round to nearest millisecond.
         int64_t delta =
             (descriptor.last_modified() - info.last_modified).InMilliseconds();
-        if (std::abs(delta) > 1)
+        if (std::labs(delta) > 1)
           return false;
       }
       if (!base::TouchFile(path, info.last_accessed, info.last_modified)) {
