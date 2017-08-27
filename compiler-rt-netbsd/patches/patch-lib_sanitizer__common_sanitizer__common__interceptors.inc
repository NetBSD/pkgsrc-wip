$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-08-03 21:24:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -4114,6 +4114,9 @@ INTERCEPTOR(int, shmctl, int shmid, int 
   // https://github.com/google/sanitizers/issues/321.
   int res = REAL(shmctl)(shmid, cmd, buf);
   if (res >= 0) {
+#if SANITIZER_NETBSD
+    unsigned sz = struct_shminfo_sz;
+#else
     unsigned sz = 0;
     if (cmd == shmctl_ipc_stat || cmd == shmctl_shm_stat)
       sz = sizeof(__sanitizer_shmid_ds);
@@ -4121,6 +4124,7 @@ INTERCEPTOR(int, shmctl, int shmid, int 
       sz = struct_shminfo_sz;
     else if (cmd == shmctl_shm_info)
       sz = struct_shm_info_sz;
+#endif
     if (sz) COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, sz);
   }
   return res;
