$NetBSD$

Add NetBSD support.

--- hw/9pfs/9p-synth.c.orig	2023-08-22 15:34:01.000000000 +0000
+++ hw/9pfs/9p-synth.c
@@ -230,6 +230,8 @@ static void synth_direntry(V9fsSynthNode
     entry->d_ino = node->attr->inode;
 #ifdef CONFIG_DARWIN
     entry->d_seekoff = off + 1;
+#elif defined(CONFIG_BSD)
+    /* not supported */
 #else
     entry->d_off = off + 1;
 #endif
@@ -433,11 +435,13 @@ static int synth_fsync(FsContext *ctx, i
 static int synth_statfs(FsContext *s, V9fsPath *fs_path,
                              struct statfs *stbuf)
 {
+#if !defined(CONFIG_BSD)
     stbuf->f_type = 0xABCD;
+#endif
     stbuf->f_bsize = 512;
     stbuf->f_blocks = 0;
     stbuf->f_files = synth_node_count;
-#ifndef CONFIG_DARWIN
+#ifdef CONFIG_LINUX
     stbuf->f_namelen = NAME_MAX;
 #endif
     return 0;
