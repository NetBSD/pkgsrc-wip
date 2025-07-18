$NetBSD$

Add support for NetBSD.

--- vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_unix.go.orig	2025-07-18 18:22:09.542741799 +0000
+++ vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || netbsd || openbsd
 
 package fs
 
@@ -47,8 +47,8 @@ func createFlockFile(flockFile string) (
 }
 
 func mustGetFreeSpace(path string) uint64 {
-	var stat unix.Statfs_t
-	if err := unix.Statfs(path, &stat); err != nil {
+	var stat statfs_t
+	if err := statfs(path, &stat); err != nil {
 		logger.Panicf("FATAL: cannot determine free disk space on %q: %s", path, err)
 	}
 	return freeSpace(stat)
