$NetBSD$

Patch pulled from upstream (Commit: bcaca24de4264f89a94069701361988007e22e58) to allow compilation with recent Boost versions
--- src/account.h.orig	2014-10-05 23:02:43.000000000 +0000
+++ src/account.h
@@ -261,11 +261,7 @@ public:
   mutable optional<xdata_t> xdata_;
 
   bool has_xdata() const {
-#if BOOST_VERSION >= 105600
-    return xdata_ != NULL;
-#else
-    return xdata_;
-#endif
+    return static_cast<bool>(xdata_);
   }
   void clear_xdata();
   xdata_t& xdata() {
