$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/base/utils/random-number-generator.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/v8/src/base/utils/random-number-generator.cc
@@ -56,7 +56,7 @@ RandomNumberGenerator::RandomNumberGener
   DCHECK_EQ(0, result);
   USE(result);
   SetSeed((static_cast<int64_t>(first_half) << 32) + second_half);
-#elif V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD
+#elif V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
   // Despite its prefix suggests it is not RC4 algorithm anymore.
   // It always succeeds while having decent performance and
   // no file descriptor involved.
