$NetBSD$

Add NetBSD support.

--- hw/9pfs/9p-proxy.c.orig	2023-08-22 15:34:01.000000000 +0000
+++ hw/9pfs/9p-proxy.c
@@ -120,7 +120,9 @@ static ssize_t socket_read(int sockfd, v
 static void prstatfs_to_statfs(struct statfs *stfs, ProxyStatFS *prstfs)
 {
     memset(stfs, 0, sizeof(*stfs));
+#if !defined(CONFIG_BSD)
     stfs->f_type = prstfs->f_type;
+#endif
     stfs->f_bsize = prstfs->f_bsize;
     stfs->f_blocks = prstfs->f_blocks;
     stfs->f_bfree = prstfs->f_bfree;
@@ -131,6 +133,8 @@ static void prstatfs_to_statfs(struct st
     /* f_namelen and f_frsize do not exist on Darwin */
     stfs->f_fsid.val[0] = prstfs->f_fsid[0] & 0xFFFFFFFFU;
     stfs->f_fsid.val[1] = prstfs->f_fsid[1] >> 32 & 0xFFFFFFFFU;
+#elif defined(CONFIG_BSD)
+    stfs->f_fsid = (unsigned long)prstfs->f_fsid[0];  
 #else
     stfs->f_fsid.__val[0] = prstfs->f_fsid[0] & 0xFFFFFFFFU;
     stfs->f_fsid.__val[1] = prstfs->f_fsid[1] >> 32 & 0xFFFFFFFFU;
