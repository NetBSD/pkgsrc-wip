$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/stat.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/stat.d
@@ -839,6 +839,70 @@ else version( DragonFlyBSD )
     extern (D) bool S_ISLNK( mode_t mode )  { return S_ISTYPE( mode, S_IFLNK );  }
     extern (D) bool S_ISSOCK( mode_t mode ) { return S_ISTYPE( mode, S_IFSOCK ); }
 }
+else version( NetBSD )
+{
+    struct stat_t
+    {
+        dev_t     st_dev;               /* inode's device */
+        mode_t    st_mode;              /* inode protection mode */
+        ino_t     st_ino;               /* inode's number */
+        nlink_t   st_nlink;             /* number of hard links */
+        uid_t     st_uid;               /* user ID of the file's owner */
+        gid_t     st_gid;               /* group ID of the file's group */
+        dev_t     st_rdev;              /* device type */
+
+        time_t    st_atime;             /* time of last access */
+        long      st_atimensec;         /* nsec of last access */
+        time_t    st_mtime;             /* time of last data modification */
+        long      st_mtimensec;         /* nsec of last data modification */
+        time_t    st_ctime;             /* time of last file status change */
+        long      st_ctimensec;         /* nsec of last file status change */
+        time_t    st_birthtime;         /* time of creation */
+        long      st_birthtimensec;     /* nsec of time of creation */
+
+        off_t     st_size;              /* file size, in bytes */
+        blkcnt_t  st_blocks;            /* blocks allocated for file */
+        blksize_t st_blksize;           /* optimal blocksize for I/O */
+        uint32_t  st_flags;             /* user defined flags for file */
+        uint32_t  st_gen;               /* file generation number */
+        uint32_t[2]  st_spare;
+    }
+
+    enum S_IRUSR    = 0x100; // octal 0000400
+    enum S_IWUSR    = 0x080; // octal 0000200
+    enum S_IXUSR    = 0x040; // octal 0000100
+    enum S_IRWXU    = 0x1C0; // octal 0000700
+
+    enum S_IRGRP    = 0x020;  // octal 0000040
+    enum S_IWGRP    = 0x010;  // octal 0000020
+    enum S_IXGRP    = 0x008;  // octal 0000010
+    enum S_IRWXG    = 0x038;  // octal 0000070
+
+    enum S_IROTH    = 0x4; // 0000004
+    enum S_IWOTH    = 0x2; // 0000002
+    enum S_IXOTH    = 0x1; // 0000001
+    enum S_IRWXO    = 0x7; // 0000007
+
+    enum S_ISUID    = 0x800; // octal 0004000
+    enum S_ISGID    = 0x400; // octal 0002000
+    enum S_ISVTX    = 0x200; // octal 0001000
+
+    private
+    {
+        extern (D) bool S_ISTYPE( mode_t mode, uint mask )
+        {
+            return ( mode & S_IFMT ) == mask;
+        }
+    }
+
+    extern (D) bool S_ISBLK( mode_t mode )  { return S_ISTYPE( mode, S_IFBLK );  }
+    extern (D) bool S_ISCHR( mode_t mode )  { return S_ISTYPE( mode, S_IFCHR );  }
+    extern (D) bool S_ISDIR( mode_t mode )  { return S_ISTYPE( mode, S_IFDIR );  }
+    extern (D) bool S_ISFIFO( mode_t mode ) { return S_ISTYPE( mode, S_IFIFO );  }
+    extern (D) bool S_ISREG( mode_t mode )  { return S_ISTYPE( mode, S_IFREG );  }
+    extern (D) bool S_ISLNK( mode_t mode )  { return S_ISTYPE( mode, S_IFLNK );  }
+    extern (D) bool S_ISSOCK( mode_t mode ) { return S_ISTYPE( mode, S_IFSOCK ); }
+}
 else version (Solaris)
 {
     private enum _ST_FSTYPSZ = 16;
@@ -1200,6 +1264,15 @@ else version( DragonFlyBSD )
     int   lstat(in char*, stat_t*);
     int   stat(in char*, stat_t*);
 }
+else version( NetBSD )
+{
+    int   __fstat50(int, stat_t*);
+    int   __lstat50(in char*, stat_t*);
+    int   __stat50(in char*, stat_t*);
+    alias __fstat50 fstat;
+    alias __lstat50 lstat;
+    alias __stat50 stat;
+}
 else version( CRuntime_Bionic )
 {
     int   fstat(int, stat_t*) @trusted;
@@ -1273,6 +1346,19 @@ else version( DragonFlyBSD )
 {
     enum S_IFMT     = 0xF000; // octal 0170000
     enum S_IFBLK    = 0x6000; // octal 0060000
+    enum S_IFCHR    = 0x2000; // octal 0020000
+    enum S_IFIFO    = 0x1000; // octal 0010000
+    enum S_IFREG    = 0x8000; // octal 0100000
+    enum S_IFDIR    = 0x4000; // octal 0040000
+    enum S_IFLNK    = 0xA000; // octal 0120000
+    enum S_IFSOCK   = 0xC000; // octal 0140000
+
+    int mknod(in char*, mode_t, dev_t);
+}
+else version( NetBSD )
+{
+    enum S_IFMT     = 0xF000; // octal 0170000
+    enum S_IFBLK    = 0x6000; // octal 0060000
     enum S_IFCHR    = 0x2000; // octal 0020000
     enum S_IFIFO    = 0x1000; // octal 0010000
     enum S_IFREG    = 0x8000; // octal 0100000
