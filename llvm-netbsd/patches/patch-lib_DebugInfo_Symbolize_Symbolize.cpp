$NetBSD$

--- lib/DebugInfo/Symbolize/Symbolize.cpp.orig	2018-06-07 17:17:06.000000000 +0000
+++ lib/DebugInfo/Symbolize/Symbolize.cpp
@@ -192,8 +192,13 @@ bool findDebugBinary(const std::string &
     Result = DebugPath.str();
     return true;
   }
+#if defined(__NetBSD__)
+  // Try /usr/libdata/debug/path/to/original_binary/debuglink_name
+  DebugPath = "/usr/libdata/debug";
+#else
   // Try /usr/lib/debug/path/to/original_binary/debuglink_name
   DebugPath = "/usr/lib/debug";
+#endif
   llvm::sys::path::append(DebugPath, llvm::sys::path::relative_path(OrigDir),
                           DebuglinkName);
   if (checkFileCRC(DebugPath, CRCHash)) {
