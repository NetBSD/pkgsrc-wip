$NetBSD$

--- internal/egl/egl.go.orig	2024-11-19 02:51:06.287897704 +0000
+++ internal/egl/egl.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build linux || windows || freebsd || openbsd
-// +build linux windows freebsd openbsd
+//go:build linux || windows || freebsd || openbsd || netbsd
+// +build linux windows freebsd openbsd netbsd
 
 package egl
 
