$NetBSD$

Add support for NetBSD.

--- ecs-cli/vendor/github.com/docker/docker/pkg/term/termios_bsd.go.orig	2020-07-07 22:09:30.000000000 +0000
+++ ecs-cli/vendor/github.com/docker/docker/pkg/term/termios_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd openbsd
+// +build darwin freebsd netbsd openbsd
 
 package term // import "github.com/docker/docker/pkg/term"
 
