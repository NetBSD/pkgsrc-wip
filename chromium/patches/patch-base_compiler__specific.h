$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/compiler_specific.h.orig	2024-09-24 20:49:13.706565100 +0000
+++ base/compiler_specific.h
@@ -326,7 +326,8 @@
 //
 // In some cases it's desirable to remove this, e.g. on hot functions, or if
 // we have purposely changed the reference canary.
-#if defined(COMPILER_GCC) || defined(__clang__)
+#if (defined(COMPILER_GCC) || defined(__clang__)) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && \
+      !defined(__NetBSD__)
 #if HAS_ATTRIBUTE(__no_stack_protector__)
 #define NO_STACK_PROTECTOR __attribute__((__no_stack_protector__))
 #else
@@ -457,7 +458,7 @@ inline constexpr bool AnalyzerAssumeTrue
 // See https://clang.llvm.org/docs/AttributeReference.html#preserve-most for
 // more details.
 #if (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
-    !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64)) &&       \
+    !((BUILDFLAG(IS_WIN) || BUILDFLAG(IS_OPENBSD)) && defined(ARCH_CPU_ARM64)) &&       \
     !defined(COMPONENT_BUILD) && defined(__clang__) &&       \
     __clang_major__ >= 17 && HAS_ATTRIBUTE(preserve_most)
 #define PRESERVE_MOST __attribute__((preserve_most))
