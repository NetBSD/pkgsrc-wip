$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -9,6 +9,8 @@ include(CheckLibraryExists)
 
 if(CMAKE_SYSTEM_NAME STREQUAL FreeBSD)
   set(CMAKE_REQUIRED_INCLUDES /usr/local/include)
+elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD)
+  set(CMAKE_REQUIRED_INCLUDES /usr/pkg/include)
 elseif(CMAKE_SYSTEM_NAME STREQUAL SunOS)
   set(CMAKE_REQUIRED_INCLUDES /opt/local/include)
 endif()
@@ -951,7 +953,7 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL FreeBS
 elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD)
   if(NOT HAVE_LIBUNWIND_H)
     unset(HAVE_LIBUNWIND_H CACHE)
-    message(WARNING "Cannot find libunwind. Try installing libunwind8 and libunwind8-dev (or the appropriate packages for your platform)")
+    message(FATAL_ERROR "Cannot find libunwind. Try installing libunwind8 and libunwind8-dev (or the appropriate packages for your platform)")
   endif()
   if(NOT HAVE_BSD_UUID_H)
     unset(HAVE_BSD_UUID_H CACHE)
@@ -959,6 +961,7 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD
   endif()
   set(DEADLOCK_WHEN_THREAD_IS_SUSPENDED_WHILE_BLOCKED_ON_MUTEX 0)
   set(PAL_PTRACE "ptrace((cmd), (pid), (void*)(addr), (data))")
+  set(BSD_REGS_STYLE "((reg).regs[_REG_##RR])")
   set(PAL_PT_ATTACH PT_ATTACH)
   set(PAL_PT_DETACH PT_DETACH)
   set(PAL_PT_READ_D PT_READ_D)
