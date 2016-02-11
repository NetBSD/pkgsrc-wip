$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/mman.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/mman.d
@@ -76,6 +76,19 @@ else version( FreeBSD )
     enum POSIX_MADV_DONTNEED    = 4;
     int posix_madvise(void *addr, size_t len, int advice);
 }
+else version( NetBSD )
+{
+    int posix_madvise(void*, size_t, int);
+
+    enum
+    {
+        POSIX_MADV_NORMAL,      /* No further special treatment */
+    	POSIX_MADV_RANDOM,      /* Expect random page references */
+    	POSIX_MADV_SEQUENTIAL,  /* Expect sequential page references */
+    	POSIX_MADV_WILLNEED,    /* Will need these pages */
+    	POSIX_MADV_DONTNEED,   	/* Don't need these pages */
+    }
+}
 else version (Solaris)
 {
 }
@@ -118,6 +131,16 @@ else version( FreeBSD )
     enum PROT_WRITE     = 0x02;
     enum PROT_EXEC      = 0x04;
 }
+else version( NetBSD )
+{
+    enum
+    {
+        PROT_NONE  = 0x00,
+	PROT_READ  = 0x01,
+	PROT_WRITE = 0x02,
+	PROT_EXEC  = 0x04,
+    }
+}
 else version (Solaris)
 {
     enum PROT_NONE = 0x00;
@@ -164,6 +187,11 @@ else version( FreeBSD )
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
@@ -318,6 +346,51 @@ else version( FreeBSD )
 
     int msync(void*, size_t, int);
 }
+else version( NetBSD )
+{
+    enum
+    {
+        MAP_SHARED       = 0x0001,      /* share changes */
+        MAP_PRIVATE      = 0x0002,      /* changes are private */
+      
+        MAP_COPY         = 0x0004,      /* "copy" region at mmap time */
+
+        MAP_FIXED        = 0x0010,      /* map addr must be exactly as requested */
+        MAP_RENAME       = 0x0020,      /* Sun: rename private pages to file */
+        MAP_NORESERVE    = 0x0040,      /* Sun: don't reserve needed swap area */
+        MAP_INHERIT      = 0x0080,      /* region is retained after exec */
+        MAP_HASSEMAPHORE = 0x0200,      /* region may contain semaphores */
+        MAP_TRYFIXED     = 0x0400,      /* attempt hint address, even within break */
+        MAP_WIRED        = 0x0800,      /* mlock() mapping when it is established */
+
+        MAP_FILE         = 0x0000,      /* map from file (default) */
+        MAP_ANONYMOUS    = 0x1000,      /* allocated from memory, swap space */
+        MAP_ANON         = MAP_ANONYMOUS,
+        MAP_STACK        = 0x2000,      /* allocated from memory, swap space (stack) */
+	/+
+    105 #define	MAP_ALIGNED(n)		((n) << MAP_ALIGNMENT_SHIFT)
+    106 #define	MAP_ALIGNMENT_SHIFT	24
+    107 #define	MAP_ALIGNMENT_MASK	MAP_ALIGNED(0xff)
+    108 #define	MAP_ALIGNMENT_64KB	MAP_ALIGNED(16)	/* 2^16 */
+    109 #define	MAP_ALIGNMENT_16MB	MAP_ALIGNED(24)	/* 2^24 */
+    110 #define	MAP_ALIGNMENT_4GB	MAP_ALIGNED(32)	/* 2^32 */
+    111 #define	MAP_ALIGNMENT_1TB	MAP_ALIGNED(40)	/* 2^40 */
+    112 #define	MAP_ALIGNMENT_256TB	MAP_ALIGNED(48)	/* 2^48 */
+    113 #define	MAP_ALIGNMENT_64PB	MAP_ALIGNED(56)	/* 2^56 */
+    114 +/
+     /*
+      * Error indicator returned by mmap(2)
+      */
+    	MAP_FAILED	= cast(void*) -1,	/* mmap() failed */
+    }
+    enum
+    {
+        MS_ASYNC      = 0x01,   /* perform asynchronous writes */
+        MS_INVALIDATE = 0x02,   /* invalidate cached data */
+        MS_SYNC       = 0x04,   /* perform synchronous writes */
+    }
+    int msync(void*, size_t, int);
+}
 else version (Solaris)
 {
     enum MAP_SHARED = 0x0001;
@@ -429,6 +502,14 @@ else version( FreeBSD )
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
@@ -473,6 +554,11 @@ else version( FreeBSD )
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
@@ -507,6 +593,10 @@ else version( FreeBSD )
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
@@ -543,6 +633,11 @@ else version( FreeBSD )
     int shm_open(in char*, int, mode_t);
     int shm_unlink(in char*);
 }
+else version( NetBSD )
+{
+    int shm_open(in char*, int, mode_t);
+    int shm_unlink(in char*);
+}
 else version (Solaris)
 {
     int shm_open(in char*, int, mode_t);
