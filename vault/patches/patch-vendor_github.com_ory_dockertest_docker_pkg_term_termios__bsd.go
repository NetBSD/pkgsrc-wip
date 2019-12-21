$NetBSD$

Add "netbsd" to build termios_bsd.go.

--- vendor/github.com/ory/dockertest/docker/pkg/term/termios_bsd.go.orig	2019-08-14 23:03:48.000000000 +0000
+++ vendor/github.com/ory/dockertest/docker/pkg/term/termios_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd openbsd
+// +build darwin freebsd openbsd netbsd
 
 package term // import "github.com/ory/dockertest/docker/pkg/term"
 
