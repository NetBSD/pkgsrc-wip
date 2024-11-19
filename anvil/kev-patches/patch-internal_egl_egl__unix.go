$NetBSD$

--- internal/egl/egl_unix.go.orig	2024-11-19 02:51:06.290682032 +0000
+++ internal/egl/egl_unix.go
@@ -1,17 +1,19 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build linux || freebsd || openbsd
-// +build linux freebsd openbsd
+//go:build linux || freebsd || openbsd || netbsd
+// +build linux freebsd openbsd netbsd
 
 package egl
 
 /*
 #cgo linux,!android  pkg-config: egl
-#cgo freebsd openbsd android LDFLAGS: -lEGL
+#cgo freebsd openbsd netbsd android LDFLAGS: -lEGL
 #cgo freebsd CFLAGS: -I/usr/local/include
 #cgo freebsd LDFLAGS: -L/usr/local/lib
 #cgo openbsd CFLAGS: -I/usr/X11R6/include
+#cgo netbsd CFLAGS: -I/usr/X11R7/include
 #cgo openbsd LDFLAGS: -L/usr/X11R6/lib
+#cgo netbsd LDFLAGS: -L/usr/X11R7/lib
 #cgo CFLAGS: -DEGL_NO_X11
 
 #include <EGL/egl.h>
