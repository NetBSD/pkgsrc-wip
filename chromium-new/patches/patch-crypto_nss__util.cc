$NetBSD$

--- crypto/nss_util.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ crypto/nss_util.cc
@@ -20,7 +20,7 @@
 #include "base/threading/thread_task_runner_handle.h"
 #include "crypto/nss_util_internal.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_BSD)
 #include <sys/mount.h>
 #include <sys/param.h>
 #endif
@@ -150,10 +150,14 @@ void UseLocalCacheOfNSSDatabaseIfNFS(con
   base::FileSystemType fs_type = base::FILE_SYSTEM_UNKNOWN;
   if (base::GetFileSystemType(database_dir, &fs_type))
     db_on_nfs = (fs_type == base::FILE_SYSTEM_NFS);
-#elif defined(OS_OPENBSD)
+#elif defined(OS_NETBSD)
+  struct statvfs buf;
+  if (statvfs(database_dir.value().c_str(), &buf) == 0)
+    db_on_nfs = (strcmp(buf.f_fstypename, "nfs") == 0);
+#elif defined(OS_BSD)
   struct statfs buf;
   if (statfs(database_dir.value().c_str(), &buf) == 0)
-    db_on_nfs = (strcmp(buf.f_fstypename, MOUNT_NFS) == 0);
+    db_on_nfs = (strcmp(buf.f_fstypename, "nfs") == 0);
 #else
   NOTIMPLEMENTED();
 #endif
