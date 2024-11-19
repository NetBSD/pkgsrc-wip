$NetBSD$

--- app/egl_x11.go.orig	2024-11-19 02:51:06.270440988 +0000
+++ app/egl_x11.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build ((linux && !android) || freebsd || openbsd) && !nox11 && !noopengl
-// +build linux,!android freebsd openbsd
+//go:build ((linux && !android) || freebsd || openbsd || netbsd) && !nox11 && !noopengl
+// +build linux,!android freebsd openbsd netbsd
 // +build !nox11
 // +build !noopengl
 
