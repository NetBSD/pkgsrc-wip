$NetBSD$

* Fix build without O_PATH

--- src/xdp-documents.c.orig	2026-01-12 10:26:48.724615416 +0000
+++ src/xdp-documents.c
@@ -96,10 +96,17 @@ xdp_register_document (const char       
   basename = g_path_get_basename (path);
   dirname = g_path_get_dirname (path);
 
+#ifdef O_PATH
   if (flags & XDP_DOCUMENT_FLAG_FOR_SAVE)
     fd = open (dirname, O_PATH | O_CLOEXEC);
   else
     fd = open (path, O_PATH | O_CLOEXEC);
+#else
+  if (flags & XDP_DOCUMENT_FLAG_FOR_SAVE)
+    fd = open (dirname, O_RDONLY | O_DIRECTORY | O_CLOEXEC);
+  else
+    fd = open (path, O_RDONLY | O_DIRECTORY | O_CLOEXEC);
+#endif
 
   if (fd == -1)
     {
