$NetBSD$

NetBSD and OpenBSD are Unix-like operating systems.

--- cmd/mountlib/mounttest/write_unix.go.orig	2020-02-01 10:40:01.000000000 +0000
+++ cmd/mountlib/mounttest/write_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin freebsd
+// +build linux darwin freebsd netbsd openbsd
 
 package mounttest
 
