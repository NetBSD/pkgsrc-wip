$NetBSD$

--- app/os_unix.go.orig	2024-11-19 02:51:06.276078130 +0000
+++ app/os_unix.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build (linux && !android) || freebsd || openbsd
-// +build linux,!android freebsd openbsd
+//go:build (linux && !android) || freebsd || openbsd || netbsd
+// +build linux,!android freebsd openbsd netbsd
 
 package app
 
