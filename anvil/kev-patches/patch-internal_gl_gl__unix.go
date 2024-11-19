$NetBSD$

--- internal/gl/gl_unix.go.orig	2024-11-19 02:51:06.293553066 +0000
+++ internal/gl/gl_unix.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build darwin || linux || freebsd || openbsd
-// +build darwin linux freebsd openbsd
+//go:build darwin || linux || freebsd || openbsd || netbsd
+// +build darwin linux freebsd openbsd netbsd
 
 package gl
 
