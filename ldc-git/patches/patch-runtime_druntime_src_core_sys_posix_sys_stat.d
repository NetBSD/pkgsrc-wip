$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/stat.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/stat.d
@@ -777,6 +777,103 @@ else version( FreeBSD )
     extern (D) bool S_ISLNK( mode_t mode )  { return S_ISTYPE( mode, S_IFLNK );  }
     extern (D) bool S_ISSOCK( mode_t mode ) { return S_ISTYPE( mode, S_IFSOCK ); }
 }
+else version( NetBSD )
+{
+    struct stat_t {
+ 	dev_t	  st_dev;		/* inode's device */
+ 	mode_t	  st_mode;		/* inode protection mode */
+ 	ino_t	  st_ino;		/* inode's number */
+ 	nlink_t	  st_nlink;		/* number of hard links */
+ 	uid_t	  st_uid;		/* user ID of the file's owner */
+ 	gid_t	  st_gid;		/* group ID of the file's group */
+ 	dev_t	  st_rdev;		/* device type */
+ // #if (_POSIX_C_SOURCE - 0) >= 200809L || (_XOPEN_SOURCE - 0) >= 700 || \
+ //    defined(_NETBSD_SOURCE)
+ 	// struct	  timespec st_atim;	/* time of last access */
+ 	// struct	  timespec st_mtim;	/* time of last data modification */
+ 	// struct	  timespec st_ctim;	/* time of last file status change */
+ 	// struct	  timespec st_birthtim;	/* time of creation */
+ // #else
+ 	time_t	  st_atime;		/* time of last access */
+ 	long	  st_atimensec;		/* nsec of last access */
+ 	time_t	  st_mtime;		/* time of last data modification */
+ 	long	  st_mtimensec;		/* nsec of last data modification */
+ 	time_t	  st_ctime;		/* time of last file status change */
+ 	long	  st_ctimensec;		/* nsec of last file status change */
+ 	time_t	  st_birthtime;		/* time of creation */
+ 	long	  st_birthtimensec;	/* nsec of time of creation */
+ // #endif
+ 	off_t	  st_size;		/* file size, in bytes */
+ 	blkcnt_t  st_blocks;		/* blocks allocated for file */
+ 	blksize_t st_blksize;		/* optimal blocksize for I/O */
+ 	uint32_t  st_flags;		/* user defined flags for file */
+ 	uint32_t  st_gen;		/* file generation number */
+ 	uint32_t[2]  st_spare;
+    }
+    enum
+    {
+        S_ISUID = 0x4<<(3*3),                 /* set user id on execution */
+        S_ISGID = 0x2<<(3*3),                 /* set group id on execution */
+        S_ISTXT = 0x1<<(3*3),                 /* sticky bit */
+    }
+    enum
+    {
+        S_IRWXU = 0x7<<(3*2),                 /* RWX mask for owner */
+        S_IRUSR = 0x4<<(3*2),                 /* R for owner */
+        S_IWUSR = 0x2<<(3*2),                 /* W for owner */
+        S_IXUSR = 0x1<<(3*2),                 /* X for owner */
+    }
+    enum
+    {
+        S_IREAD        = S_IRUSR,
+        S_IWRITE       = S_IWUSR,
+        S_IEXEC        = S_IXUSR,
+    }
+    enum
+    {
+        S_IRWXG = 0x7<<(3*1),                 /* RWX mask for group */
+        S_IRGRP = 0x4<<(3*1),                 /* R for group */
+        S_IWGRP = 0x2<<(3*1),                 /* W for group */
+        S_IXGRP = 0x1<<(3*1),                 /* X for group */
+    }
+    enum
+    {
+        S_IRWXO = 0x7<<(3*0),                 /* RWX mask for other */
+        S_IROTH = 0x4<<(3*0),                 /* R for other */
+        S_IWOTH = 0x2<<(3*0),                 /* W for other */
+        S_IXOTH = 0x1<<(3*0),                 /* X for other */
+    }
+    private
+    {
+        extern (D) bool S_ISTYPE( mode_t mode, uint mask )
+        {
+            return ( mode & S_IFMT ) == mask;
+        }
+    }
+    extern (D) bool S_ISBLK( mode_t mode )  { return S_ISTYPE( mode, S_IFBLK );  }
+    extern (D) bool S_ISCHR( mode_t mode )  { return S_ISTYPE( mode, S_IFCHR );  }
+    extern (D) bool S_ISDIR( mode_t mode )  { return S_ISTYPE( mode, S_IFDIR );  }
+    extern (D) bool S_ISFIFO( mode_t mode ) { return S_ISTYPE( mode, S_IFIFO );  }
+    extern (D) bool S_ISREG( mode_t mode )  { return S_ISTYPE( mode, S_IFREG );  }
+    extern (D) bool S_ISLNK( mode_t mode )  { return S_ISTYPE( mode, S_IFLNK );  }
+    extern (D) bool S_ISSOCK( mode_t mode ) { return S_ISTYPE( mode, S_IFSOCK ); }
+/* MISSING:
+S_ISVTX
+
+S_TYPEISMQ(buf)
+S_TYPEISSEM(buf)
+S_TYPEISSHM(buf)
+*/
+    int    chmod(in char*, mode_t);
+    int    fchmod(int, mode_t);
+    int    fstat(int, stat_t*);
+    int    lstat(in char*, stat_t*);
+    int    mkdir(in char*, mode_t);
+    int    mkfifo(in char*, mode_t);
+    int    stat(in char*, stat_t*);
+    mode_t umask(mode_t);
+
+}
 else version (Solaris)
 {
     private enum _ST_FSTYPSZ = 16;
@@ -1174,6 +1271,41 @@ else version( FreeBSD )
 
     int mknod(in char*, mode_t, dev_t);
 }
+else version( NetBSD )
+{
+    enum
+    {
+	_S_IFMT	  = 0xf<<(3*4),		/* type of file mask */
+	_S_IFIFO  = 0x1<<(3*4),		/* named pipe (fifo) */
+	_S_IFCHR  = 0x2<<(3*4),		/* character special */
+	_S_IFDIR  = 0x4<<(3*4),		/* directory */
+	_S_IFBLK  = 0x6<<(3*4),		/* block special */
+	_S_IFREG  = 0x1<<(3*5),		/* regular */
+	_S_IFLNK  = 0xa<<(3*4),		/* symbolic link */
+	_S_ISVTX  = 0x1<<(3*3),		/* save swapped text even after use */
+	_S_IFSOCK = 0xc<<(3*4),		/* socket */
+	_S_IFWHT  = 0xe<<(3*4),		/* whiteout */
+	_S_ARCH1  = 0x2<<(3*5),		/* Archive state 1, ls -l shows 'a' */
+	_S_ARCH2  = 0x4<<(3*5),		/* Archive state 2, ls -l shows 'A' */
+    }
+    enum
+    {
+	S_IFMT   = _S_IFMT,
+	S_IFIFO  = _S_IFIFO,
+	S_IFCHR  = _S_IFCHR,
+	S_IFDIR  = _S_IFDIR,
+	S_IFBLK  = _S_IFBLK,
+	S_IFREG  = _S_IFREG,
+	S_IFLNK  = _S_IFLNK,
+	S_ISVTX  = _S_ISVTX,
+	S_IFSOCK = _S_IFSOCK,
+   	S_IFWHT  = _S_IFWHT,
+    	S_ARCH1  = _S_ARCH1,
+    	S_ARCH2  = _S_ARCH2,
+    }
+
+    int mknod(in char*, mode_t, dev_t);
+}
 else version (Solaris)
 {
     enum S_IFMT = 0xF000;
