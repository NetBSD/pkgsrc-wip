$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-01-31 18:28:53.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -79,6 +79,7 @@ check_struct_has_member ("struct stat" s
 check_struct_has_member ("struct stat" st_atimensec "sys/types.h;sys/stat.h" HAVE_STAT_NSEC)
 check_struct_has_member ("struct tm" tm_gmtoff time.h HAVE_TM_GMTOFF)
 check_struct_has_member ("ucontext_t" uc_mcontext.gregs[0] ucontext.h HAVE_GREGSET_T)
+check_struct_has_member ("ucontext_t" uc_mcontext.__gregs[0] ucontext.h HAVE___GREGSET_T)
 
 set(CMAKE_EXTRA_INCLUDE_FILES machine/reg.h)
 check_type_size("struct reg" BSD_REGS_T)
@@ -89,7 +90,7 @@ set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES signal.h)
 check_type_size(siginfo_t SIGINFO_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
-set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h)
+set(CMAKE_EXTRA_INCLUDE_FILES ucontext.h sys/ucontext.h)
 check_type_size(ucontext_t UCONTEXT_T)
 set(CMAKE_EXTRA_INCLUDE_FILES)
 set(CMAKE_EXTRA_INCLUDE_FILES pthread.h)
@@ -937,6 +938,7 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL FreeBS
   set(PAL_PT_READ_D PT_READ_D)
   set(PAL_PT_WRITE_D PT_WRITE_D)
   set(HAS_FTRUNCATE_LENGTH_ISSUE 0)
+  set(HAVE_REG_R_REGS 1)
 
   if(EXISTS "/lib/libc.so.7")
     set(FREEBSD_LIBC "/lib/libc.so.7")
@@ -960,6 +962,7 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD
   set(PAL_PT_READ_D PT_READ_D)
   set(PAL_PT_WRITE_D PT_WRITE_D)
   set(HAS_FTRUNCATE_LENGTH_ISSUE 0)
+  set(HAVE_REG__R_REGS 1)
 
 elseif(CMAKE_SYSTEM_NAME STREQUAL SunOS)
   if(NOT HAVE_LIBUNWIND_H)
