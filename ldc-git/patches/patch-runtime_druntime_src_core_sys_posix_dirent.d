$NetBSD$

--- runtime/druntime/src/core/sys/posix/dirent.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/dirent.d
@@ -142,6 +142,42 @@ else version( FreeBSD )
 
     dirent* readdir(DIR*);
 }
+else version( NetBSD )
+{
+    alias _dirdesc DIR;
+
+    struct _dirdesc {
+        /*
+         * dd_fd should be kept intact to preserve ABI compat.  see dirfd().
+         */
+        int     dd_fd;          /* file descriptor associated with directory */
+        /*
+         * the rest is hidden from user.
+         */
+        long    dd_loc;         /* offset in current buffer */
+        long    dd_size;        /* amount of data returned by getdents */
+        char*   dd_buf;         /* data buffer */
+        int     dd_len;         /* size of data buffer */
+        off_t   dd_seek;        /* magic cookie returned by getdents */
+        void*   dd_internal;    /* state for seekdir/telldir */
+        int     dd_flags;       /* flags for readdir */
+        void    *dd_lock;       /* lock for concurrent access */
+    }
+
+    enum MAXNAMLEN = 511;      	/* must be kept in sync with NAME_MAX */
+    struct dirent {
+ 	ino_t               d_fileno;	/* file number of entry */
+ 	ushort              d_reclen;	/* length of this record */
+ 	ushort              d_namlen;	/* length of string in d_name */
+ 	ubyte               d_type;	/* file type, see below */
+ 	char[MAXNAMLEN + 1] d_name;	/* name must be no longer than this */
+    }
+
+    int     closedir(DIR*);
+    DIR*    opendir(in char*);
+    dirent* readdir(DIR*);
+    void    rewinddir(DIR*);
+}
 else version (Solaris)
 {
     struct dirent
@@ -237,6 +273,10 @@ else version( FreeBSD )
 {
     int readdir_r(DIR*, dirent*, dirent**);
 }
+else version( NetBSD )
+{
+    int readdir_r(DIR*, dirent*, dirent**);
+}
 else version (Solaris)
 {
     static if (__USE_LARGEFILE64)
@@ -276,6 +316,11 @@ else version( FreeBSD )
     void   seekdir(DIR*, c_long);
     c_long telldir(DIR*);
 }
+else version( NetBSD )
+{
+    void   seekdir(DIR*, c_long);
+    c_long telldir(DIR*);
+}
 else version (OSX)
 {
 }
