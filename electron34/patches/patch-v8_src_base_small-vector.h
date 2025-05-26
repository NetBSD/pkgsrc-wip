$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/base/small-vector.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/base/small-vector.h
@@ -22,7 +22,7 @@ template <typename T, size_t kSize, type
 class SmallVector {
   // Currently only support trivially copyable and trivially destructible data
   // types, as it uses memcpy to copy elements and never calls destructors.
-  ASSERT_TRIVIALLY_COPYABLE(T);
+  // XXX FREEBSD ASSERT_TRIVIALLY_COPYABLE(T);
   static_assert(std::is_trivially_destructible<T>::value);
 
  public:
