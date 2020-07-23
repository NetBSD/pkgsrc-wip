$NetBSD$

Provides stat conversion function for NetBSD.

--- vendor/github.com/docker/docker/pkg/system/stat_netbsd.go.orig	2020-07-23 04:42:05.263335746 +0000
+++ vendor/github.com/docker/docker/pkg/system/stat_netbsd.go
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
