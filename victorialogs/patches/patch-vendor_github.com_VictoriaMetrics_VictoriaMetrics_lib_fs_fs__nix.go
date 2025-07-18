$NetBSD$

Add support for NetBSD.

--- vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_nix.go.orig	2025-07-18 18:56:39.551124810 +0000
+++ vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_nix.go
@@ -10,7 +10,9 @@ import (
 	"golang.org/x/sys/unix"
 )
 
-func freeSpace(stat unix.Statfs_t) uint64 {
+type statfs_t = unix.Statfs_t
+
+func freeSpace(stat statfs_t) uint64 {
 	return uint64(stat.Bavail) * uint64(stat.Bsize)
 }
 
@@ -22,3 +24,7 @@ func mustRemoveDirAtomic(dir string) {
 	}
 	MustRemoveAll(tmpDir)
 }
+
+func statfs(path string, stat *statfs_t) (err error) {
+	return unix.Statfs(path, stat)
+}
