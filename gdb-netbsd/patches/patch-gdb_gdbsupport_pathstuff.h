$NetBSD$

--- gdb/gdbsupport/pathstuff.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbsupport/pathstuff.h
@@ -92,4 +92,6 @@ extern const char *get_shell ();
 
 extern gdb::char_vector make_temp_filename (const std::string &f);
 
+extern "C" char *canonicalize_file_name (const char *path);
+
 #endif /* COMMON_PATHSTUFF_H */
