$NetBSD$

--- src/ptrace/_UPT_access_fpreg.c.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/ptrace/_UPT_access_fpreg.c
@@ -73,7 +73,11 @@ _UPT_access_fpreg (unw_addr_space_t as, 
 {
   struct UPT_info *ui = arg;
   pid_t pid = ui->pid;
+#if defined __NetBSD__
+  __fpregset_t fpreg;
+#else
   fpregset_t fpreg;
+#endif
 
 #if defined(__amd64__)
   if (1) /* XXXKIB */
@@ -97,7 +101,11 @@ _UPT_access_fpreg (unw_addr_space_t as, 
           return -UNW_EBADREG;
   if (write) {
 #if defined(__amd64__)
+#if defined __NetBSD__
+          memcpy(&((struct fxsave*)&fpreg)->fx_xmm[reg], val, sizeof(unw_fpreg_t));
+#else
           memcpy(&fpreg.fpr_xacc[reg], val, sizeof(unw_fpreg_t));
+#endif
 #elif defined(__i386__)
           memcpy(&fpreg.fpr_acc[reg], val, sizeof(unw_fpreg_t));
 #elif defined(__arm__)
@@ -111,7 +119,11 @@ _UPT_access_fpreg (unw_addr_space_t as, 
                   return -UNW_EBADREG;
   } else
 #if defined(__amd64__)
+#if defined __NetBSD__
+          memcpy(val, &((struct fxsave*)&fpreg)->fx_xmm[reg], sizeof(unw_fpreg_t));
+#else
           memcpy(val, &fpreg.fpr_xacc[reg], sizeof(unw_fpreg_t));
+#endif
 #elif defined(__i386__)
           memcpy(val, &fpreg.fpr_acc[reg], sizeof(unw_fpreg_t));
 #elif defined(__arm__)
