$NetBSD$

Provides stat conversion function for NetBSD.

--- vendor/github.com/ory/dockertest/docker/pkg/system/stat_netbsd.go.orig	2019-09-08 00:43:25.064582087 +0000
+++ vendor/github.com/ory/dockertest/docker/pkg/system/stat_netbsd.go
@@ -0,0 +1,13 @@
+package system // import "github.com/ory/dockertest/docker/pkg/system"
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
