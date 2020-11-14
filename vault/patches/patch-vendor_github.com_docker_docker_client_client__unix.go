$NetBSD$

Build client_unix.go for NetBSD.

--- vendor/github.com/docker/docker/client/client_unix.go.orig	2020-07-18 02:21:10.000000000 +0000
+++ vendor/github.com/docker/docker/client/client_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd openbsd darwin
+// +build linux freebsd openbsd netbsd darwin
 
 package client // import "github.com/docker/docker/client"
 
