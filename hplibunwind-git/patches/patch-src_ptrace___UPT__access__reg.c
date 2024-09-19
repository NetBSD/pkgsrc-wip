$NetBSD$

--- src/ptrace/_UPT_access_reg.c.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/ptrace/_UPT_access_reg.c
@@ -318,7 +318,11 @@ _UPT_access_reg (unw_addr_space_t as, un
 {
   struct UPT_info *ui = arg;
   pid_t pid = ui->pid;
+#if defined __NetBSD__
+  __gregset_t regs;
+#else
   gregset_t regs;
+#endif
   char *r;
 
 #if UNW_DEBUG
