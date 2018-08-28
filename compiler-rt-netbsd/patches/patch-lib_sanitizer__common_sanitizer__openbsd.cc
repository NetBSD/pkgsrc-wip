$NetBSD$

--- lib/sanitizer_common/sanitizer_openbsd.cc.orig	2018-08-21 21:25:38.000000000 +0000
+++ lib/sanitizer_common/sanitizer_openbsd.cc
@@ -56,7 +56,7 @@ uptr ReadBinaryName(/*out*/char *buf, up
   struct kinfo_proc kp;
   size_t kl;
   const int Mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
-  if (sysctl(Mib, ARRAY_SIZE(Mib), &kp, &kl, NULL, 0) != -1)
+  if (internal_sysctl(Mib, ARRAY_SIZE(Mib), &kp, &kl, NULL, 0) != -1)
     return internal_snprintf(buf,
                              (KI_MAXCOMLEN < buf_len ? KI_MAXCOMLEN : buf_len),
                              "%s", kp.p_comm);
@@ -68,19 +68,19 @@ static void GetArgsAndEnv(char ***argv, 
   size_t nenv;
   int argvmib[4] = {CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_ARGV};
   int envmib[4] = {CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_ENV};
-  if (sysctl(argvmib, 4, NULL, &nargv, NULL, 0) == -1) {
+  if (internal_sysctl(argvmib, 4, NULL, &nargv, NULL, 0) == -1) {
     Printf("sysctl KERN_PROC_NARGV failed\n");
     Die();
   }
-  if (sysctl(envmib, 4, NULL, &nenv, NULL, 0) == -1) {
+  if (internal_sysctl(envmib, 4, NULL, &nenv, NULL, 0) == -1) {
     Printf("sysctl KERN_PROC_NENV failed\n");
     Die();
   }
-  if (sysctl(argvmib, 4, &argv, &nargv, NULL, 0) == -1) {
+  if (internal_sysctl(argvmib, 4, &argv, &nargv, NULL, 0) == -1) {
     Printf("sysctl KERN_PROC_ARGV failed\n");
     Die();
   }
-  if (sysctl(envmib, 4, &envp, &nenv, NULL, 0) == -1) {
+  if (internal_sysctl(envmib, 4, &envp, &nenv, NULL, 0) == -1) {
     Printf("sysctl KERN_PROC_ENV failed\n");
     Die();
   }
