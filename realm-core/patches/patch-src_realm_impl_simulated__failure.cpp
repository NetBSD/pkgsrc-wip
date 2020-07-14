$NetBSD$

--- src/realm/impl/simulated_failure.cpp.orig	2020-06-30 08:11:11.000000000 +0000
+++ src/realm/impl/simulated_failure.cpp
@@ -27,7 +27,7 @@
 #include <realm/util/basic_system_errors.hpp>
 #include <realm/impl/simulated_failure.hpp>
 
-#if REALM_PLATFORM_APPLE || REALM_ANDROID
+#if REALM_PLATFORM_APPLE || REALM_ANDROID || REALM_NETBSD
 #define USE_PTHREADS_IMPL 1
 #else
 #define USE_PTHREADS_IMPL 0
