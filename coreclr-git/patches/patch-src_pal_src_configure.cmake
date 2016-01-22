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
@@ -96,7 +98,7 @@ check_type_size(off_t SIZEOF_OFF_T)
 
 check_cxx_symbol_exists(SYS_yield sys/syscall.h HAVE_YIELD_SYSCALL)
 check_cxx_symbol_exists(INFTIM poll.h HAVE_INFTIM)
-check_cxx_symbol_exists(CHAR_BIT sys/limits.h HAVE_CHAR_BIT)
+check_cxx_symbol_exists(CHAR_BIT limits.h HAVE_CHAR_BIT)
 check_cxx_symbol_exists(_DEBUG sys/user.h USER_H_DEFINES_DEBUG)
 check_cxx_symbol_exists(_SC_PHYS_PAGES unistd.h HAVE__SC_PHYS_PAGES)
 check_cxx_symbol_exists(_SC_AVPHYS_PAGES unistd.h HAVE__SC_AVPHYS_PAGES)
