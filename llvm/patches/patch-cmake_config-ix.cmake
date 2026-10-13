$NetBSD: patch-cmake_config-ix.cmake,v 1.8 2022/11/14 18:44:05 adam Exp $

Do not generate invalid llvm-config in pkgsrc.
Allow override of pthread library selection via PKGSRC_LLVM_PTHREADLIB.

--- cmake/config-ix.cmake.orig	2026-10-06 07:38:51.000000000 +0000
+++ cmake/config-ix.cmake
@@ -154,7 +154,11 @@ if(HAVE_LIBPTHREAD)
   set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
   set(THREADS_HAVE_PTHREAD_ARG Off)
   find_package(Threads REQUIRED)
-  set(LLVM_PTHREAD_LIB ${CMAKE_THREAD_LIBS_INIT})
+  if(PKGSRC_LLVM_PTHREADLIB)
+    set(LLVM_PTHREAD_LIB ${PKGSRC_LLVM_PTHREADLIB})
+  else()
+    set(LLVM_PTHREAD_LIB ${CMAKE_THREAD_LIBS_INIT})
+  endif()
   if(LLVM_PTHREAD_LIB)
     list(APPEND CMAKE_REQUIRED_LIBRARIES ${LLVM_PTHREAD_LIB})
   endif()
