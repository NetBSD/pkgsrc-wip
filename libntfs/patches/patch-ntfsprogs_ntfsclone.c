$NetBSD$

--- ntfsprogs/ntfsclone.c.orig	2016-09-11 13:57:41.776108524 +0000
+++ ntfsprogs/ntfsclone.c	2016-09-11 14:08:04.560295452 +0000
@@ -71,6 +71,19 @@
  */
 #define NTFS_DO_NOT_CHECK_ENDIANS
 
+#ifdef __NetBSD__
+#  include <sys/param.h>
+    /* NetBSD version later than 2.99.9 have statvfs(2) instead of statfs(2) */
+#  if __NetBSD_Version__ >= 299000900
+#	include <sys/statvfs.h>
+#	define F_TYPE	f_fsid
+#  else
+#	define F_TYPE	f_type
+#  endif
+#else
+#  define F_TYPE	f_type
+#endif
+
 #include "debug.h"
 #include "types.h"
 #include "support.h"
@@ -164,8 +177,12 @@
 	char *output;
 	char *volume;
 #ifndef NO_STATFS
+#if defined(__NetBSD__) && (__NetBSD_Version__ >= 299000900)
+	struct statvfs stfs;
+#else
 	struct statfs stfs;
 #endif
+#endif
 } opt;
 
 struct bitmap {
@@ -842,7 +859,7 @@
 #ifndef NO_STATFS
 		int err = errno;
 		perr_printf("Write failed");
-		if (err == EIO && opt.stfs.f_type == 0x517b)
+		if (err == EIO && opt.stfs.F_TYPE == 0x517b)
 			Printf("Apparently you tried to clone to a remote "
 			       "Windows computer but they don't\nhave "
 			       "efficient sparse file handling by default. "
@@ -2262,7 +2279,7 @@
 		Printf("WARNING: Couldn't get filesystem type: "
 		       "%s\n", strerror(errno));
 	else
-		fs_type = opt.stfs.f_type;
+		fs_type = opt.stfs.F_TYPE;
 
 	if (fs_type == 0x52654973)
 		Printf("WARNING: You're using ReiserFS, it has very poor "
