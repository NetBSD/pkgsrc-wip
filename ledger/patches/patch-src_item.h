$NetBSD$

Patch pulled from upstream (Commit: bcaca24de4264f89a94069701361988007e22e58) to allow compilation with recent Boost versions
--- src/item.h.orig	2014-10-05 23:02:43.000000000 +0000
+++ src/item.h
@@ -191,11 +191,7 @@ public:
   static bool use_aux_date;
 
   virtual bool has_date() const {
-#if BOOST_VERSION >= 105600
-    return _date != NULL;
-#else
-    return _date;
-#endif
+    return static_cast<bool>(_date);
   }
 
   virtual date_t date() const {
