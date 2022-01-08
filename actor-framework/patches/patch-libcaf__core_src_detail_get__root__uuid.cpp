$NetBSD$

* Add Solaris support

--- libcaf_core/src/detail/get_root_uuid.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/detail/get_root_uuid.cpp
@@ -192,7 +192,7 @@ std::string get_root_uuid() {
 } // namespace detail
 } // namespace caf
 
-#elif defined(CAF_IOS) || defined(CAF_ANDROID)
+#elif defined(CAF_IOS) || defined(CAF_ANDROID) || defined(CAF_SOLARIS)
 
 // return a randomly-generated UUID on mobile devices
 
