$NetBSD$

Add NetBSD support.

--- hw/9pfs/9p.c.orig	2023-08-22 15:34:01.000000000 +0000
+++ hw/9pfs/9p.c
@@ -136,7 +136,7 @@ static int dotl_to_open_flags(int flags)
         { P9_DOTL_NONBLOCK, O_NONBLOCK } ,
         { P9_DOTL_DSYNC, O_DSYNC },
         { P9_DOTL_FASYNC, FASYNC },
-#ifndef CONFIG_DARWIN
+#ifdef CONFIG_LINUX
         { P9_DOTL_NOATIME, O_NOATIME },
         /*
          *  On Darwin, we could map to F_NOCACHE, which is
@@ -3574,7 +3574,11 @@ static int v9fs_fill_statfs(V9fsState *s
     if (!bsize_factor) {
         bsize_factor = 1;
     }
+#if !defined(CONFIG_BSD)
     f_type  = stbuf->f_type;
+#else
+    f_type = 0xef53;
+#endif
     f_bsize = stbuf->f_bsize;
     f_bsize *= bsize_factor;
     /*
@@ -3591,6 +3595,9 @@ static int v9fs_fill_statfs(V9fsState *s
     fsid_val = (unsigned int)stbuf->f_fsid.val[0] |
                (unsigned long long)stbuf->f_fsid.val[1] << 32;
     f_namelen = NAME_MAX;
+#elif defined(CONFIG_BSD)
+    fsid_val = (unsigned long) stbuf->f_fsid;
+    f_namelen = NAME_MAX;
 #else
     fsid_val = (unsigned int) stbuf->f_fsid.__val[0] |
                (unsigned long long)stbuf->f_fsid.__val[1] << 32;
@@ -3979,6 +3986,9 @@ out_nofid:
  * Linux guests.
  */
 #define P9_XATTR_SIZE_MAX 65536
+#elif defined(CONFIG_BSD)
+/* XXX not implemented */
+#define P9_XATTR_SIZE_MAX 65536
 #else
 #error Missing definition for P9_XATTR_SIZE_MAX for this host system
 #endif
