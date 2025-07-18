$NetBSD$

Add support for NetBSD.

--- vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_netbsd.go.orig	2025-07-18 18:29:16.524144368 +0000
+++ vendor/github.com/VictoriaMetrics/VictoriaMetrics/lib/fs/fs_netbsd.go
@@ -0,0 +1,28 @@
+package fs
+
+import (
+	"fmt"
+	"os"
+
+	"github.com/VictoriaMetrics/VictoriaMetrics/lib/logger"
+	"golang.org/x/sys/unix"
+)
+
+type statfs_t = unix.Statvfs_t
+
+func freeSpace(stat statfs_t) uint64 {
+	return uint64(stat.Bavail) * uint64(stat.Bsize)
+}
+
+func mustRemoveDirAtomic(dir string) {
+	n := atomicDirRemoveCounter.Add(1)
+	tmpDir := fmt.Sprintf("%s.must-remove.%d", dir, n)
+	if err := os.Rename(dir, tmpDir); err != nil {
+		logger.Panicf("FATAL: cannot move %s to %s: %s", dir, tmpDir, err)
+	}
+	MustRemoveAll(tmpDir)
+}
+
+func statfs(path string, buf *statfs_t) (err error) {
+	return unix.Statvfs(path, buf)
+}
