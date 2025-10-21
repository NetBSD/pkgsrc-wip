$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/compiler_specific.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/compiler_specific.h
@@ -388,7 +388,7 @@ inline constexpr bool AnalyzerAssumeTrue
 // See https://clang.llvm.org/docs/AttributeReference.html#preserve-most for
 // more details.
 #if (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
-    !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64)) &&       \
+    !((BUILDFLAG(IS_WIN) || BUILDFLAG(IS_OPENBSD)) && defined(ARCH_CPU_ARM64)) &&       \
     !defined(COMPONENT_BUILD) && defined(__clang__) &&       \
     __clang_major__ >= 17 && HAS_ATTRIBUTE(preserve_most)
 #define PRESERVE_MOST __attribute__((preserve_most))
