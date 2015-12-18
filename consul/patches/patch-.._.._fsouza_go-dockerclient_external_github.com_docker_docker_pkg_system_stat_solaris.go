$NetBSD$

Rudimentary SunOS support based on community patches by @MerlinDMC.

https://github.com/hashicorp/consul/issues/159

--- ../../fsouza/go-dockerclient/external/github.com/docker/docker/pkg/system/stat_solaris.go.orig	2015-12-17 12:43:25.131247327 +0000
+++ ../../fsouza/go-dockerclient/external/github.com/docker/docker/pkg/system/stat_solaris.go
@@ -0,0 +1,17 @@
+// +build solaris
+
+package system
+
+import (
+       "syscall"
+)
+
+// fromStatT creates a system.StatT type from a syscall.Stat_t type
+func fromStatT(s *syscall.Stat_t) (*StatT, error) {
+       return &StatT{size: s.Size,
+               mode: uint32(s.Mode),
+               uid:  s.Uid,
+               gid:  s.Gid,
+               rdev: uint64(s.Rdev),
+               mtim: s.Mtim}, nil
+}
