$NetBSD$

--- vendor/github.com/go-gl/glfw/v3.3/glfw/native_linbsd.go.orig	2021-12-16 15:57:57.000000000 +0000
+++ vendor/github.com/go-gl/glfw/v3.3/glfw/native_linbsd.go
@@ -1,4 +1,5 @@
-// +build linux,!wayland freebsd,!wayland openbsd
+//go:build (linux && !wayland) || (freebsd && !wayland) || openbsd || netbsd
+// +build linux,!wayland freebsd,!wayland openbsd netbsd
 
 package glfw
 
