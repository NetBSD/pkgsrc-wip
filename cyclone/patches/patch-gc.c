$NetBSD$

Concurrencykit returns an integer as a pointer here, and the warning
-Wint-conversion results in a compiler error. Concurrencykit is
choosing an integer size to match the pointer size (using implementations
which are per-compiler/architecture), so just cast to (uintptr_t) to
give a valid pointer type for ck_pr_add_ptr.

--- gc.c.orig	2025-12-27 10:58:55.457517996 +0000
+++ gc.c
@@ -2763,9 +2763,9 @@ void gc_merge_all_heaps(gc_thread_data *
     if (hdest && hsrc) {
       gc_heap_merge(hdest, hsrc);
       ck_pr_add_ptr(&(dest->cached_heap_total_sizes[heap_type]),
-                    ck_pr_load_ptr(&(src->cached_heap_total_sizes[heap_type])));
+                    (uintptr_t)ck_pr_load_ptr(&(src->cached_heap_total_sizes[heap_type])));
       ck_pr_add_ptr(&(dest->cached_heap_free_sizes[heap_type]),
-                    ck_pr_load_ptr(&(src->cached_heap_free_sizes[heap_type])));
+                    (uintptr_t)ck_pr_load_ptr(&(src->cached_heap_free_sizes[heap_type])));
     }
   }
   ck_pr_add_int(&(dest->heap_num_huge_allocations),
