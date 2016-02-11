$NetBSD$

--- runtime/druntime/src/core/sys/posix/fcntl.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/fcntl.d
@@ -367,6 +367,88 @@ else version( FreeBSD )
     int creat(in char*, mode_t);
     int open(in char*, int, ...);
 }
+else version( NetBSD )
+{
+    enum
+    {
+        F_DUPFD		= 0,		/* duplicate file descriptor */
+	F_GETFD		= 1,		/* get file descriptor flags */
+	F_SETFD		= 2,		/* set file descriptor flags */
+	F_GETFL		= 3,		/* get file status flags */
+	F_SETFL		= 4,		/* set file status flags */
+	F_GETOWN	= 5,		/* get SIGIO/SIGURG proc/pgrp */
+	F_SETOWN	= 6,		/* set SIGIO/SIGURG proc/pgrp */
+
+	F_GETLK		= 7,		/* get record locking information */
+	F_SETLK		= 8,		/* set record locking information */
+	F_SETLKW	= 9,		/* F_SETLK; wait if blocked */
+
+	F_CLOSEM	= 10,		/* close all fds >= to the one given */
+	F_MAXFD		= 11,		/* return the max open fd */
+	F_DUPFD_CLOEXEC	= 12,		/* close on exec duplicated fd */
+	F_GETNOSIGPIPE	= 13,		/* get SIGPIPE disposition */
+	F_SETNOSIGPIPE	= 14,		/* set SIGPIPE disposition */
+    }
+    enum FD_CLOEXEC	= 1;		/* close-on-exec flag */
+    enum
+    {
+	F_RDLCK		= 1,		/* shared or read lock */
+	F_UNLCK		= 2,		/* unlock */
+	F_WRLCK		= 3,		/* exclusive or write lock */
+    }
+    enum
+    {
+        //FREAD		0x00000001
+        //FWRITE		0x00000002
+
+        O_NONBLOCK	= 0x00000004,	/* no delay */
+        O_APPEND	= 0x00000008,	/* set append mode */
+
+	//O_SHLOCK	0x00000010	/* open with shared file lock */
+	//O_EXLOCK	0x00000020	/* open with exclusive file lock */
+	//O_ASYNC		0x00000040	/* signal pgrp when data ready */
+
+	O_SYNC		= 0x00000080,	/* synchronous writes */
+
+	//O_NOFOLLOW	0x00000100	/* don't follow symlinks on the last */
+ 					/* path component */
+        O_CREAT		= 0x00000200,	/* create if nonexistent */
+	O_TRUNC		= 0x00000400,	/* truncate to zero length */
+	O_EXCL		= 0x00000800,	/* error if already exists */
+ /* defined by POSIX 1003.1; BSD default, but required to be bitwise distinct */
+        O_NOCTTY	= 0x00008000,	/* don't assign controlling terminal */
+ 
+	O_DSYNC		= 0x00010000,	/* write: I/O data completion */
+	O_RSYNC		= 0x00020000,	/* read: I/O completion as for write */
+
+	//O_ALT_IO	0x00040000	/* use alternate i/o semantics */
+	//O_DIRECT	0x00080000	/* direct I/O hint */
+ 
+	//O_DIRECTORY	0x00200000	/* fail if not a directory */
+	//O_CLOEXEC	0x00400000	/* set close on exec */
+
+	//O_SEARCH	0x00800000	/* skip search permission checks */
+
+	//O_NOSIGPIPE	0x01000000	/* don't deliver sigpipe */
+    }
+    enum
+    {
+	O_RDONLY	= 0x00000000,	/* open for reading only */
+	O_WRONLY	= 0x00000001,	/* open for writing only */
+	O_RDWR		= 0x00000002,	/* open for reading and writing */
+	O_ACCMODE	= 0x00000003,	/* mask for above modes */
+    }
+    struct flock {
+     	off_t	l_start;	/* starting offset */
+     	off_t	l_len;		/* len = 0 means until end of file */
+     	pid_t	l_pid;		/* lock owner */
+     	short	l_type;		/* lock type: read/write, etc. */
+     	short	l_whence;	/* type of l_start */
+    }
+    int creat(in char*, mode_t);
+    int fcntl(int, int, ...);
+    int open(in char*, int, ...);
+}
 else version (Solaris)
 {
     enum F_DUPFD = 0;
