$NetBSD$

9pfs uses statfs(2) alot. Rather than patching all the code to use
statvfs(2) on NetBSD, provide wrapper functions that emulate statfs(2).

--- hw/9pfs/netbsd-statfs-compat.h.orig	2023-09-17 10:56:07.671982907 +0000
+++ hw/9pfs/netbsd-statfs-compat.h
@@ -0,0 +1,53 @@
+#ifndef QEMU_NETBSD_STATFS_COMPAT_H
+#define QEMU_NETBSD_STATFS_COMPAT_H
+
+#include <sys/statvfs.h>
+
+/* this is just struct statvfs from sys/statvfs.h */
+
+struct statfs {
+	unsigned long	f_flag;		/* copy of mount exported flags */
+	unsigned long	f_bsize;	/* file system block size */
+	unsigned long	f_frsize;	/* fundamental file system block size */
+	unsigned long	f_iosize;	/* optimal file system block size */
+
+	/* The following are in units of f_frsize */
+	fsblkcnt_t	f_blocks;	/* number of blocks in file system, */
+	fsblkcnt_t	f_bfree;	/* free blocks avail in file system */
+	fsblkcnt_t	f_bavail;	/* free blocks avail to non-root */
+	fsblkcnt_t	f_bresvd;	/* blocks reserved for root */
+
+	fsfilcnt_t	f_files;	/* total file nodes in file system */
+	fsfilcnt_t	f_ffree;	/* free file nodes in file system */
+	fsfilcnt_t	f_favail;	/* free file nodes avail to non-root */
+	fsfilcnt_t	f_fresvd;	/* file nodes reserved for root */
+
+	uint64_t  	f_syncreads;	/* count of sync reads since mount */
+	uint64_t  	f_syncwrites;	/* count of sync writes since mount */
+
+	uint64_t  	f_asyncreads;	/* count of async reads since mount */
+	uint64_t  	f_asyncwrites;	/* count of async writes since mount */
+
+	fsid_t		f_fsidx;	/* NetBSD compatible fsid */
+	unsigned long	f_fsid;		/* Posix compatible fsid */
+	unsigned long	f_namemax;	/* maximum filename length */
+	uid_t		f_owner;	/* user that mounted the file system */
+
+	uint64_t	f_spare[4];	/* spare space */
+
+	char	f_fstypename[_VFS_NAMELEN];	/* fs type name */
+	char	f_mntonname[_VFS_MNAMELEN];	/* directory on which mounted */
+	char	f_mntfromname[_VFS_MNAMELEN];	/* mounted file system */
+	char	f_mntfromlabel[_VFS_MNAMELEN];  /* disk label name if avail */
+
+};
+
+static inline int statfs(const char *path, struct statfs *buf) {
+	return statvfs(path, (struct statvfs *)buf);
+}
+
+static inline int fstatfs(int fd, struct statfs *buf) {
+	return fstatvfs(fd, (struct statvfs *)buf);
+}
+
+#endif
