$NetBSD$

* Fix statfs on NetBSD

--- document-portal/permission-db.c.orig	2025-05-20 17:07:14.000000000 +0000
+++ document-portal/permission-db.c
@@ -33,6 +33,11 @@
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/statvfs.h>
+#define statfs statvfs
+#define MFSNAMELEN _VFS_NAMELEN
+#endif
 
 #include "permission-db.h"
 #include "gvdb/gvdb-reader.h"
@@ -257,7 +262,11 @@ is_on_nfs (const char *path)
   if (statfs_result != 0)
     return FALSE;
 
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+  return (strncmp(statfs_buffer.f_fstypename, "nfs", MFSNAMELEN) == 0);
+#else
   return statfs_buffer.f_type == 0x6969;
+#endif
 }
 
 static gboolean
