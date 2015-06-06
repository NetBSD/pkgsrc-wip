$NetBSD: patch-src_mp3fs.c,v 1.2 2015/06/06 15:22:29 thomasklausner Exp $

First chunk:
Second chunk: needed at least on NetBSD, otherwise every start
gives "Error parsing options."

--- src/mp3fs.c.orig	2014-05-14 19:48:45.000000000 +0000
+++ src/mp3fs.c
@@ -57,12 +57,12 @@ enum {
 #define MP3FS_OPT(t, p, v) { t, offsetof(struct mp3fs_params, p), v }
 
 static struct fuse_opt mp3fs_opts[] = {
-    MP3FS_OPT("--quality=%u",     quality, 0),
-    MP3FS_OPT("quality=%u",       quality, 0),
+    MP3FS_OPT("--quality=%d",     quality, 0),
+    MP3FS_OPT("quality=%d",       quality, 0),
     MP3FS_OPT("-d",               debug, 1),
     MP3FS_OPT("debug",            debug, 1),
-    MP3FS_OPT("-b %u",            bitrate, 0),
-    MP3FS_OPT("bitrate=%u",       bitrate, 0),
+    MP3FS_OPT("-b %d",            bitrate, 0),
+    MP3FS_OPT("bitrate=%d",       bitrate, 0),
     MP3FS_OPT("--gainmode=%d",    gainmode, 0),
     MP3FS_OPT("gainmode=%d",      gainmode, 0),
     MP3FS_OPT("--gainref=%f",     gainref, 0),
@@ -138,7 +138,7 @@ static int mp3fs_opt_proc(void* data, co
             exit(0);
     }
 
-    return 1;
+    return 0;
 }
 
 int main(int argc, char *argv[]) {
