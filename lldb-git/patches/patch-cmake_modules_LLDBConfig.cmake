$NetBSD$

--- cmake/modules/LLDBConfig.cmake.orig	2017-01-28 19:35:14.000000000 +0000
+++ cmake/modules/LLDBConfig.cmake
@@ -29,6 +29,9 @@ set(LLDB_DISABLE_CURSES ${LLDB_DEFAULT_D
 set(LLDB_RELOCATABLE_PYTHON 0 CACHE BOOL
   "Causes LLDB to use the PYTHONHOME environment variable to locate Python.")
 
+set(LLDB_USE_SYSTEM_SIX 0 CACHE BOOL
+  "Use six.py shipped with system and do not install a copy of it")
+
 if (NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(LLDB_EXPORT_ALL_SYMBOLS 0 CACHE BOOL
     "Causes lldb to export all symbols when building liblldb.")
