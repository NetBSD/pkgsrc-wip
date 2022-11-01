$NetBSD$

Move the ok flag out of the destruct_guard_t so that GCC won't optimise
~destruct_guard_t() into a NO-OP.

--- kernel/rtlil.h.orig	2022-10-05 09:30:38.000000000 +0000
+++ kernel/rtlil.h
@@ -85,10 +85,10 @@ namespace RTLIL
 
 		// the global id string cache
 
+		static bool destruct_guard_ok; // POD, will be initialized to zero
 		static struct destruct_guard_t {
-			bool ok; // POD, will be initialized to zero
-			destruct_guard_t() { ok = true; }
-			~destruct_guard_t() { ok = false; }
+			destruct_guard_t() { destruct_guard_ok = true; }
+			~destruct_guard_t() { destruct_guard_ok = false; }
 		} destruct_guard;
 
 		static std::vector<char*> global_id_storage_;
@@ -147,7 +147,7 @@ namespace RTLIL
 
 		static int get_reference(const char *p)
 		{
-			log_assert(destruct_guard.ok);
+			log_assert(destruct_guard_ok);
 
 			if (!p[0])
 				return 0;
@@ -225,7 +225,7 @@ namespace RTLIL
 		{
 			// put_reference() may be called from destructors after the destructor of
 			// global_refcount_storage_ has been run. in this case we simply do nothing.
-			if (!destruct_guard.ok || !idx)
+			if (!destruct_guard_ok || !idx)
 				return;
 
 		#ifdef YOSYS_XTRACE_GET_PUT
