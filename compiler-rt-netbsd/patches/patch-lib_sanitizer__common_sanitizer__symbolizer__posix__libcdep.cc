$NetBSD$

--- lib/sanitizer_common/sanitizer_symbolizer_posix_libcdep.cc.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_symbolizer_posix_libcdep.cc
@@ -77,6 +77,7 @@ static swift_demangle_ft swift_demangle_
 // symbolication.
 static void InitializeSwiftDemangler() {
   swift_demangle_f = (swift_demangle_ft)dlsym(RTLD_DEFAULT, "swift_demangle");
+  (void)dlerror(); // Cleanup error message in case of failure
 }
 
 // Attempts to demangle a Swift name. The demangler will return nullptr if a
