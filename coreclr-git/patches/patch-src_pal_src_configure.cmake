$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-01-23 16:23:38.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -12,7 +12,7 @@ if(CMAKE_SYSTEM_NAME STREQUAL FreeBSD)
 elseif(CMAKE_SYSTEM_NAME STREQUAL SunOS)
   set(CMAKE_REQUIRED_INCLUDES /opt/local/include)
 endif()
-if(NOT CMAKE_SYSTEM_NAME STREQUAL Darwin AND NOT CMAKE_SYSTEM_NAME STREQUAL FreeBSD)
+if(NOT CMAKE_SYSTEM_NAME STREQUAL Darwin AND NOT CMAKE_SYSTEM_NAME STREQUAL FreeBSD AND NOT CMAKE_SYSTEM_NAME STREQUAL NetBSD)
   set(CMAKE_REQUIRED_DEFINITIONS "-D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L")
 endif()
 
@@ -75,6 +75,7 @@ check_struct_has_member ("struct stat" s
 check_struct_has_member ("struct stat" st_atimensec "sys/types.h;sys/stat.h" HAVE_STAT_NSEC)
 check_struct_has_member ("struct tm" tm_gmtoff time.h HAVE_TM_GMTOFF)
 check_struct_has_member ("ucontext_t" uc_mcontext.gregs[0] ucontext.h HAVE_GREGSET_T)
+check_struct_has_member ("ucontext_t" uc_mcontext.__gregs[0] ucontext.h HAVE___GREGSET_T)
 
 set(CMAKE_EXTRA_INCLUDE_FILES machine/reg.h)
 check_type_size("struct reg" BSD_REGS_T)
@@ -85,7 +86,7 @@ set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES signal.h)
 check_type_size(siginfo_t SIGINFO_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
-set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h)
+set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h sys/ucontext.h)
 check_type_size(ucontext_t UCONTEXT_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES pthread.h)
