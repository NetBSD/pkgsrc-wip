$NetBSD$

--- lib/asan/asan_interceptors.h.orig	2017-07-03 15:33:06.521004205 +0000
+++ lib/asan/asan_interceptors.h
@@ -34,7 +34,7 @@
 # define ASAN_INTERCEPT_FORK 0
 #endif
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 # define ASAN_USE_ALIAS_ATTRIBUTE_FOR_INDEX 1
 #else
 # define ASAN_USE_ALIAS_ATTRIBUTE_FOR_INDEX 0
