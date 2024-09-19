$NetBSD: patch-mfbt_Poison.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

* Use posix_madvise(3) instead of madvise(3) for Solaris/SunOS.
  Solaris/SunOS's madvise(3) is not enabled in this context,
  and its first argument type is different from NetBSD/Linux's one.

--- mfbt/Poison.cpp.orig	2013-09-11 03:22:45.000000000 +0000
+++ mfbt/Poison.cpp
@@ -125,7 +125,11 @@ ReleaseRegion(void *region, uintptr_t si
 static bool
 ProbeRegion(uintptr_t region, uintptr_t size)
 {
+#if !defined(__sun)
   if (madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+#else
+  if (posix_madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
