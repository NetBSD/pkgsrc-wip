$NetBSD$

# Fix build with clang19

--- ext/bifrost/src/DataStorage.tcc.orig	2025-05-27 13:48:42.121940805 +0000
+++ ext/bifrost/src/DataStorage.tcc
@@ -78,7 +78,10 @@ DataStorage<U>::DataStorage(const DataSt
 
         unitig_cs_link = new atomic<uint64_t>[sz_link];
 
-        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.sz_link[i].load();
+	// Hayzam Sherif: o.sz_link -> o.unitig_cs_link
+	// Independently proposed by Lucas van Dijk:
+	// https://github.com/pmelsted/bifrost/pull/18/files
+        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.unitig_cs_link[i].load();
     }
 
     if ((o.data != nullptr) && (o.sz_cs != 0)){
