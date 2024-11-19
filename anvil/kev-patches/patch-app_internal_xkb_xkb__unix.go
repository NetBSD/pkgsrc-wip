$NetBSD$

--- app/internal/xkb/xkb_unix.go.orig	2024-11-19 02:51:06.273286272 +0000
+++ app/internal/xkb/xkb_unix.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build (linux && !android) || freebsd || openbsd
-// +build linux,!android freebsd openbsd
+//go:build (linux && !android) || freebsd || openbsd || netbsd
+// +build linux,!android freebsd openbsd netbsd
 
 // Package xkb implements a Go interface for the X Keyboard Extension library.
 package xkb
@@ -21,8 +21,8 @@ import (
 
 /*
 #cgo linux pkg-config: xkbcommon
-#cgo freebsd openbsd CFLAGS: -I/usr/local/include
-#cgo freebsd openbsd LDFLAGS: -L/usr/local/lib -lxkbcommon
+#cgo freebsd openbsd netbsd CFLAGS: -I/usr/local/include
+#cgo freebsd openbsd netbsd LDFLAGS: -L/usr/local/lib -lxkbcommon
 
 #include <stdlib.h>
 #include <xkbcommon/xkbcommon.h>
