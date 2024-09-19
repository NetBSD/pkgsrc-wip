$NetBSD$

- Fix NetBSD support.

--- src/fs.cc.orig	2020-07-27 12:01:52.000000000 +0000
+++ src/fs.cc
@@ -42,7 +42,7 @@
 #include <sys/statfs.h>
 #endif
 
-#if defined(__sun)
+#if defined(__sun) || defined(__NetBSD__)
 #include <sys/statvfs.h>
 #include <sys/types.h>
 #endif
@@ -58,8 +58,8 @@
 #endif
 
 #if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined(__OpenBSD__) &&  \
-    !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__sun) && \
-    !defined(__HAIKU__) && !(defined(__APPLE__) && defined(__MACH__))
+    !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && \
+    !defined(__sun) && !defined(__HAIKU__) && !(defined(__APPLE__) && defined(__MACH__))
 #include <mntent.h>
 #endif
 
@@ -126,14 +126,18 @@ struct fs_stat *prepare_fs_stat(const ch
 #endif /* defined(__APPLE__) */
 
 static void update_fs_stat(struct fs_stat *fs) {
-#if defined(__sun)
+#if defined(__sun) || defined(__NetBSD__)
   struct statvfs s;
 
   if (statvfs(fs->path, &s) == 0) {
     fs->size = (long long)s.f_blocks * s.f_frsize;
     fs->avail = (long long)s.f_bavail * s.f_frsize;
     fs->free = (long long)s.f_bfree * s.f_frsize;
+#if defined(__NetBSD__)
+    (void)strncpy(fs->type, s.f_fstypename, sizeof(fs->type));
+#else
     (void)strncpy(fs->type, s.f_basetype, sizeof(fs->type));
+#endif
 #else
   struct statfs_struct s {};
 
@@ -165,7 +169,7 @@ void get_fs_type(const char *path, char 
     NORM_ERR("statfs '%s': %s", path, strerror(errno));
   }
   return;
-#elif defined(__sun)
+#elif defined(__sun) || defined(__NetBSD__)
   assert(0); /* not used - see update_fs_stat() */
 #else  /* HAVE_STRUCT_STATFS_F_FSTYPENAME */
 
