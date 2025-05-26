$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/native_library_posix.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/native_library_posix.cc
@@ -34,7 +34,7 @@ NativeLibrary LoadNativeLibraryWithOptio
   // http://crbug.com/17943, http://crbug.com/17557, http://crbug.com/36892,
   // and http://crbug.com/40794.
   int flags = RTLD_LAZY;
-#if BUILDFLAG(IS_ANDROID) || !defined(RTLD_DEEPBIND)
+#if BUILDFLAG(IS_ANDROID) || !defined(RTLD_DEEPBIND) || BUILDFLAG(IS_BSD)
   // Certain platforms don't define RTLD_DEEPBIND. Android dlopen() requires
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
