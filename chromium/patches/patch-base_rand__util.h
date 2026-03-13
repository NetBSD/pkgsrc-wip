$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/rand_util.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ base/rand_util.h
@@ -225,7 +225,7 @@ decltype(auto) RandomChoice(Range&& r) {
   return r[base::RandGenerator(r.size())];
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
