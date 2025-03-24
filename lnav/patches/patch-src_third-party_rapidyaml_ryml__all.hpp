$NetBSD: patch-src_third-party_rapidyaml_ryml__all.hpp,v 1.2 2023/01/17 10:18:33 wiz Exp $

Add NetBSD support.
https://github.com/tstack/lnav/pull/1106

--- src/third-party/rapidyaml/ryml_all.hpp.orig	2025-02-12 19:26:00.000000000 +0000
+++ src/third-party/rapidyaml/ryml_all.hpp
@@ -346,7 +346,7 @@ C4_FOR_EACH(PRN_STRUCT_OFFSETS, a, b, c)
 #elif defined(__linux__) || defined(__linux)
 #   define C4_UNIX
 #   define C4_LINUX
-#elif defined(__unix__) || defined(__unix)
+#elif defined(__unix__) || defined(__unix) || defined(__NetBSD__)
 #   define C4_UNIX
 #elif defined(__arm__) || defined(__aarch64__)
 #   define C4_ARM
@@ -356,7 +356,7 @@ C4_FOR_EACH(PRN_STRUCT_OFFSETS, a, b, c)
 #   error "unknown platform"
 #endif
 
-#if defined(__posix) || defined(C4_UNIX) || defined(C4_LINUX)
+#if defined(__posix) || defined(C4_UNIX) || defined(C4_LINUX) || defined(__NetBSD__)
 #   define C4_POSIX
 #endif
 
