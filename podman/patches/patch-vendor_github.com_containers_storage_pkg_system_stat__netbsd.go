$NetBSD$

--- vendor/github.com/containers/storage/pkg/system/stat_netbsd.go.orig	2021-09-04 12:43:05.852178601 +0000
+++ vendor/github.com/containers/storage/pkg/system/stat_netbsd.go
@@ -0,0 +1,13 @@
+package system
+
+import "syscall"
+
+// fromStatT converts a syscall.Stat_t type to a system.Stat_t type
+func fromStatT(s *syscall.Stat_t) (*StatT, error) {
+	return &StatT{size: s.Size,
+		mode: uint32(s.Mode),
+		uid:  s.Uid,
+		gid:  s.Gid,
+		rdev: uint64(s.Rdev),
+		mtim: s.Mtimespec}, nil
+}
