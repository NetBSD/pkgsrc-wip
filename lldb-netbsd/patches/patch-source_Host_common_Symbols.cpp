$NetBSD$

--- source/Host/common/Symbols.cpp.orig	2017-03-26 19:17:32.000000000 +0000
+++ source/Host/common/Symbols.cpp
@@ -212,8 +212,13 @@ FileSpec Symbols::LocateExecutableSymbol
     debug_file_search_paths.AppendIfUnique(FileSpec(".", true));
 
 #ifndef LLVM_ON_WIN32
+#if defined(__NetBSD__)
+    // Add /usr/libdata/debug directory.
+    debug_file_search_paths.AppendIfUnique(FileSpec("/usr/libdata/debug", true));
+#else
     // Add /usr/lib/debug directory.
     debug_file_search_paths.AppendIfUnique(FileSpec("/usr/lib/debug", true));
+#endif
 #endif // LLVM_ON_WIN32
 
     std::string uuid_str;
