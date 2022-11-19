$NetBSD$

Fix build for NetBSD.

github.com/moby/sys/mount needs to be ported on NetBSD.

--- vendor/github.com/moby/sys/mount/mount_unix.go.orig	2022-10-25 17:53:02.000000000 +0000
+++ vendor/github.com/moby/sys/mount/mount_unix.go
@@ -1,4 +1,4 @@
-// +build !darwin,!windows
+// +build !darwin,!netbsd,!windows
 
 package mount
 
