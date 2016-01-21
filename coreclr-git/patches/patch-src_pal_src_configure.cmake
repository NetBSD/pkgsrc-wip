$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -943,7 +943,27 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL FreeBS
   else()
     message(FATAL_ERROR "Cannot find libc on this system.")
   endif()
-  
+
+elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD)
+  if(NOT HAVE_LIBUNWIND_H)
+    unset(HAVE_LIBUNWIND_H CACHE)
+    message(WARNING "Cannot find libunwind. Try installing libunwind8 and libunwind8-dev (or the appropriate packages for your platform)")
+  endif()
+  if(NOT HAVE_BSD_UUID_H)
+    unset(HAVE_BSD_UUID_H CACHE)
+    message(FATAL_ERROR "Cannot find uuid.h")
+  endif()
+  set(DEADLOCK_WHEN_THREAD_IS_SUSPENDED_WHILE_BLOCKED_ON_MUTEX 0)
+  set(PAL_PTRACE "ptrace((cmd), (pid), (void*)(addr), (data))")
+  set(PAL_PT_ATTACH PT_ATTACH)
+  set(PAL_PT_DETACH PT_DETACH)
+  set(PAL_PT_READ_D PT_READ_D)
+  set(PAL_PT_WRITE_D PT_WRITE_D)
+  set(JA_JP_LOCALE_NAME ja_JP_LOCALE_NOT_FOUND)
+  set(KO_KR_LOCALE_NAME ko_KR_LOCALE_NOT_FOUND)
+  set(ZH_TW_LOCALE_NAME zh_TW_LOCALE_NOT_FOUND)
+  set(HAS_FTRUNCATE_LENGTH_ISSUE 0)
+
 elseif(CMAKE_SYSTEM_NAME STREQUAL SunOS)
   if(NOT HAVE_LIBUNWIND_H)
     unset(HAVE_LIBUNWIND_H CACHE)
@@ -989,4 +1009,3 @@ else() # Anything else is Linux
 endif(CMAKE_SYSTEM_NAME STREQUAL Darwin)
 
 configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
-
