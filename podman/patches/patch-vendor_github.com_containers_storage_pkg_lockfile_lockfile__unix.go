$NetBSD$

--- vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go
@@ -1,4 +1,4 @@
-// +build linux solaris darwin freebsd
+// +build linux solaris darwin freebsd netbsd
 
 package lockfile
 
