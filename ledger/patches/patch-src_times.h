$NetBSD$

Patch pulled from upstream (Commit: bcaca24de4264f89a94069701361988007e22e58) to allow compilation with recent Boost versions
--- src/times.h.orig	2014-10-05 23:02:43.000000000 +0000
+++ src/times.h
@@ -568,11 +568,7 @@ public:
   void   stabilize(const optional<date_t>& date = none);
 
   bool   is_valid() const {
-#if BOOST_VERSION >= 105600
-    return start != NULL;
-#else
-    return start;
-#endif
+    return static_cast<bool>(start);
   }
 
   /** Find the current or next period containing date.  Returns false if
