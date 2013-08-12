$NetBSD: patch-grub-core_loader_i386_pc_plan9.c,v 1.2 2013/08/12 15:02:24 gregoire Exp $

Prevent warning with lang/gcc44, leading to build failure.

--- grub-core/loader/i386/pc/plan9.c.orig	2013-08-12 11:30:38.000000000 +0000
+++ grub-core/loader/i386/pc/plan9.c
@@ -358,6 +358,8 @@ fill_disk (const char *name, void *data)
   return 0;
 }
 
+#pragma GCC diagnostic ignored "-Wstrict-aliasing"
+
 static grub_err_t
 grub_cmd_plan9 (grub_extcmd_context_t ctxt, int argc, char *argv[])
 {
