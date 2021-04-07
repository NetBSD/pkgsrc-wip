$NetBSD$

Add support for NetBSD.

--- ../github.com/containerd/containerd@v1.4.3/sys/stat_bsd.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ ../github.com/containerd/containerd@v1.4.3/sys/stat_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd
+// +build darwin freebsd netbsd
 
 /*
    Copyright The containerd Authors.
