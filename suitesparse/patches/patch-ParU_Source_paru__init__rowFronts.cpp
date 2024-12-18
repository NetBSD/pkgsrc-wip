$NetBSD$

# Silence compiler error on Alma8: Sym is predetermined 'shared'

--- ParU/Source/paru_init_rowFronts.cpp.orig	2024-12-18 14:04:59.003674095 +0000
+++ ParU/Source/paru_init_rowFronts.cpp
@@ -439,7 +439,7 @@ ParU_Info paru_init_rowFronts
     // copying Diag_map
     if (Diag_map)
     {
-        #pragma omp taskloop default(none) shared(Sym, Diag_map, inv_Diag_map) \
+        #pragma omp taskloop default(none) shared(Diag_map, inv_Diag_map) \
         grainsize(512)
         for (int64_t i = 0; i < Sym->n; i++)
         {
