$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -35,7 +35,6 @@ check_include_files(libunwind.h HAVE_LIB
 check_include_files(runetype.h HAVE_RUNETYPE_H)
 check_include_files(lttng/tracepoint.h HAVE_LTTNG_TRACEPOINT_H)
 check_include_files(uuid/uuid.h HAVE_LIBUUID_H)
-check_include_files(uuid.h HAVE_BSD_UUID_H)
 
 check_function_exists(kqueue HAVE_KQUEUE)
 check_function_exists(getpwuid_r HAVE_GETPWUID_R)
@@ -111,6 +110,16 @@ check_cxx_symbol_exists(_SC_PHYS_PAGES u
 check_cxx_symbol_exists(_SC_AVPHYS_PAGES unistd.h HAVE__SC_AVPHYS_PAGES)
 
 check_cxx_source_runs("
+#include <uuid.h>
+
+int main(void) {
+  uuid_t uuid;
+  uint32_t status;
+  uuid_create(&uuid, &status);
+  return 0;
+}" HAVE_BSD_UUID_H)
+
+check_cxx_source_runs("
 #include <sys/param.h>
 #include <stdlib.h>
 
