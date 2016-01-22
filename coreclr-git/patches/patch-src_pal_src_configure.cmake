$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-01-22 10:23:14.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -46,7 +46,9 @@ check_library_exists(pthread pthread_get
 check_library_exists(pthread pthread_sigqueue "" HAVE_PTHREAD_SIGQUEUE)
 check_function_exists(sigreturn HAVE_SIGRETURN)
 check_function_exists(_thread_sys_sigreturn HAVE__THREAD_SYS_SIGRETURN)
+set(CMAKE_REQUIRED_LIBRARIES m)
 check_function_exists(copysign HAVE_COPYSIGN)
+set(CMAKE_REQUIRED_LIBRARIES)
 check_function_exists(fsync HAVE_FSYNC)
 check_function_exists(futimes HAVE_FUTIMES)
 check_function_exists(utimes HAVE_UTIMES)
