$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/shm.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/shm.d
@@ -121,6 +121,32 @@ else version( FreeBSD )
     int   shmdt(in void*);
     int   shmget(key_t, size_t, int);
 }
+else version( NetBSD )
+{
+    enum SHM_RDONLY     = 0x01000; // 010000
+    enum SHM_RND        = 0x02000; // 020000
+    enum SHMLBA         = 1 << 12; // PAGE_SIZE = (1<<PAGE_SHIFT)
+
+    alias c_ulong   shmatt_t;
+
+    struct shmid_ds
+    {
+        ipc_perm        shm_perm;
+        size_t             shm_segsz;
+        pid_t           shm_lpid;
+        pid_t           shm_cpid;
+        short           shm_nattch;
+        time_t          shm_atime;
+        time_t          shm_dtime;
+        time_t          shm_ctime;
+        void*           shm_internal;
+    }
+
+    void* shmat(int, in void*, int);
+    int   shmctl(int, int, shmid_ds*);
+    int   shmdt(in void*);
+    int   shmget(key_t, size_t, int);
+}
 else version( OSX )
 {
 
