$NetBSD$

Add support for NetBSD.

--- ../github.com/containerd/containerd@v1.4.3/content/local/store_unix.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ ../github.com/containerd/containerd@v1.4.3/content/local/store_unix.go
@@ -1,4 +1,4 @@
-// +build linux solaris darwin freebsd
+// +build linux solaris darwin freebsd netbsd
 
 /*
    Copyright The containerd Authors.
