$NetBSD$

--- src/Native/Runtime/unix/configure.cmake.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/unix/configure.cmake
@@ -906,6 +906,28 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL FreeBS
     message(FATAL_ERROR "Cannot find libc on this system.")
   endif()
   
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
+  set(USE_SIGNALS_FOR_THREAD_SUSPENSION 1)
+  set(JA_JP_LOCALE_NAME ja_JP_LOCALE_NOT_FOUND)
+  set(KO_KR_LOCALE_NAME ko_KR_LOCALE_NOT_FOUND)
+  set(ZH_TW_LOCALE_NAME zh_TW_LOCALE_NOT_FOUND)
+  set(HAS_FTRUNCATE_LENGTH_ISSUE 0)
+
 else() # Anything else is Linux
   if(NOT HAVE_LIBUNWIND_H)
     unset(HAVE_LIBUNWIND_H CACHE)
