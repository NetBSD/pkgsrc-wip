$NetBSD$

Add support for NetBSD and DragonFly BSD.

Backport from upstream commit:

 <https://github.com/moby/moby/commit/87a7fc1ced93430cd301d55bec4ff5fb353493a5>

--- ecs-cli/vendor/github.com/docker/docker/client/client_unix.go.orig	2020-07-07 22:09:30.000000000 +0000
+++ ecs-cli/vendor/github.com/docker/docker/client/client_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd openbsd darwin
+// +build linux freebsd netbsd openbsd darwin dragonfly
 
 package client // import "github.com/docker/docker/client"
 
