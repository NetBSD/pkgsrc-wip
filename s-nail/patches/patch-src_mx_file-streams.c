$NetBSD$

--- src/mx/file-streams.c.orig	2026-05-01 14:13:28.869490321 +0000
+++ src/mx/file-streams.c
@@ -1020,7 +1020,7 @@ mx_fs_pipe_cloxy(sz fd[2], BITENUM(u8,mx_fs_cloxy) wha
 
 #if !defined mx_HAVE_PIPE2
 	if((what != mx_FS_CLOXY_NONE) && (!mx_fs_fd_cloxy_ensure(fd[0], what, mx_FS_CLOXY_NONE) ||
-			!mx_fs_cloxy_ensure(fd[1], what, mx_FS_CLOXY_NONE)))
+			!mx_fs_fd_cloxy_ensure(fd[1], what, mx_FS_CLOXY_NONE)))
 		goto jerr;
 #endif
 
