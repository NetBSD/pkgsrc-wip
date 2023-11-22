$NetBSD$

Avoid using libdwarf because the version coming with NetBSD is too old
and doesn't provide all needed symbols.

--- CMake/folly-deps.cmake.orig	2023-11-22 17:56:23.282105254 +0000
+++ CMake/folly-deps.cmake
@@ -173,7 +173,7 @@ CHECK_INCLUDE_FILE_CXX(elf.h FOLLY_HAVE_
 find_package(Backtrace)
 
 set(FOLLY_HAVE_BACKTRACE ${Backtrace_FOUND})
-set(FOLLY_HAVE_DWARF ${LIBDWARF_FOUND})
+set(FOLLY_HAVE_DWARF FALSE)
 if (NOT WIN32 AND NOT APPLE)
   set(FOLLY_USE_SYMBOLIZER ON)
 endif()
