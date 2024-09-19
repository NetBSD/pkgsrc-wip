$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/mman.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/mman.d
@@ -85,6 +85,16 @@ else version( DragonFlyBSD )
     enum POSIX_MADV_DONTNEED    = 4;
     int posix_madvise(void *addr, size_t len, int advice);
 }
+else version( NetBSD )
+{
+    enum POSIX_MADV_NORMAL      = 0;
+    enum POSIX_MADV_RANDOM      = 1;
+    enum POSIX_MADV_SEQUENTIAL  = 2;
+    enum POSIX_MADV_WILLNEED    = 3;
+    enum POSIX_MADV_DONTNEED    = 4;
+    int posix_madvise(void *addr, size_t len, int advice);
+}
+
 else version (Solaris)
 {
 }
@@ -134,6 +144,13 @@ else version( DragonFlyBSD )
     enum PROT_WRITE     = 0x02;
     enum PROT_EXEC      = 0x04;
 }
+else version( NetBSD )
+{
+    enum PROT_NONE      = 0x00;
+    enum PROT_READ      = 0x01;
+    enum PROT_WRITE     = 0x02;
+    enum PROT_EXEC      = 0x04;
+}
 else version (Solaris)
 {
     enum PROT_NONE = 0x00;
@@ -185,6 +202,11 @@ else version( DragonFlyBSD )
     void* mmap(void*, size_t, int, int, int, off_t);
     int   munmap(void*, size_t);
 }
+else version( NetBSD )
+{
+    void* mmap(void*, size_t, int, int, int, off_t);
+    int   munmap(void*, size_t);
+}
 else version (Solaris)
 {
     void* mmap(void*, size_t, int, int, int, off_t);
@@ -354,6 +376,21 @@ else version( DragonFlyBSD )
 
     int msync(void*, size_t, int);
 }
+else version( NetBSD )
+{
+    enum MAP_SHARED     = 0x0001;
+    enum MAP_PRIVATE    = 0x0002;
+    enum MAP_FIXED      = 0x0010;
+    enum MAP_ANON       = 0x1000;
+
+    enum MAP_FAILED     = cast(void*)-1;
+
+    enum MS_SYNC        = 0x0000;
+    enum MS_ASYNC       = 0x0001;
+    enum MS_INVALIDATE  = 0x0002;
+
+    int msync(void*, size_t, int);
+}
 else version (Solaris)
 {
     enum MAP_SHARED = 0x0001;
@@ -477,6 +514,14 @@ else version( DragonFlyBSD )
     int mlockall(int);
     int munlockall();
 }
+else version( NetBSD )
+{
+    enum MCL_CURRENT    = 0x0001;
+    enum MCL_FUTURE     = 0x0002;
+
+    int mlockall(int);
+    int munlockall();
+}
 else version (Solaris)
 {
     enum MCL_CURRENT = 0x0001;
@@ -526,6 +571,11 @@ else version( DragonFlyBSD )
     int mlock(in void*, size_t);
     int munlock(in void*, size_t);
 }
+else version( NetBSD )
+{
+    int mlock(in void*, size_t);
+    int munlock(in void*, size_t);
+}
 else version (Solaris)
 {
     int mlock(in void*, size_t);
@@ -564,6 +614,10 @@ else version( DragonFlyBSD )
 {
     int mprotect(void*, size_t, int);
 }
+else version( NetBSD )
+{
+    int mprotect(void*, size_t, int);
+}
 else version (Solaris)
 {
     int mprotect(void*, size_t, int);
@@ -604,6 +658,11 @@ else version( DragonFlyBSD )
 {
     int shm_open(in char*, int, mode_t);
     int shm_unlink(in char*);
+}
+else version( NetBSD )
+{
+    int shm_open(in char*, int, mode_t);
+    int shm_unlink(in char*);
 }
 else version (Solaris)
 {
