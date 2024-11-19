$NetBSD$

--- gpu/headless/headless_egl.go.orig	2024-11-19 02:51:06.285095013 +0000
+++ gpu/headless/headless_egl.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build linux || freebsd || openbsd
-// +build linux freebsd openbsd
+//go:build linux || freebsd || openbsd || netbsd
+// +build linux freebsd openbsd netbsd
 
 package headless
 
