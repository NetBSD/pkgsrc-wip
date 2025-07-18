$NetBSD$

Add support for NetBSD.

--- vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_openbsd.go.orig	2025-07-18 18:59:00.607090098 +0000
+++ vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_openbsd.go
@@ -8,6 +8,8 @@ import (
 	"golang.org/x/sys/unix"
 )
 
+type statfs_t = unix.Statfs_t
+
 func freeSpace(stat unix.Statfs_t) uint64 {
 	return uint64(stat.F_bavail) * uint64(stat.F_bsize)
 }
@@ -20,3 +22,7 @@ func mustRemoveDirAtomic(dir string) {
 	}
 	MustRemoveAll(tmpDir)
 }
+
+func statfs(path string, stat *statfs_t) (err error) {
+	return unix.Statfs(path, stat)
+}
