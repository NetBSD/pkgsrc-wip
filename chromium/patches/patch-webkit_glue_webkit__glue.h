$NetBSD: patch-webkit_glue_webkit__glue.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/glue/webkit_glue.h.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/glue/webkit_glue.h
@@ -288,7 +288,7 @@ bool LaunchSelLdr(const char* alleged_ur
                   void* nacl_process_handle, int* nacl_process_id);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Return a read-only file descriptor to the font which best matches the given
 // properties or -1 on failure.
 //   charset: specifies the language(s) that the font must cover. See
