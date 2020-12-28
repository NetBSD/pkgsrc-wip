$NetBSD$

Add support for NetBSD.

Shared upstream via:

 https://github.com/moby/sys/pull/60

--- vendor/github.com/moby/sys/mount/flags_bsd.go.orig	2020-12-15 02:27:14.000000000 +0000
+++ vendor/github.com/moby/sys/mount/flags_bsd.go
@@ -1,4 +1,4 @@
-// +build freebsd openbsd
+// +build freebsd netbsd openbsd
 
 package mount
 
