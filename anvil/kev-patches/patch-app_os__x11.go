$NetBSD$

--- app/os_x11.go.orig	2024-11-19 02:51:06.281829414 +0000
+++ app/os_x11.go
@@ -1,7 +1,7 @@
 // SPDX-License-Identifier: Unlicense OR MIT
 
-//go:build ((linux && !android) || freebsd || openbsd) && !nox11
-// +build linux,!android freebsd openbsd
+//go:build ((linux && !android) || freebsd || openbsd || netbsd) && !nox11
+// +build linux,!android freebsd openbsd netbsd
 // +build !nox11
 
 package app
@@ -9,7 +9,8 @@ package app
 /*
 #cgo freebsd openbsd CFLAGS: -I/usr/X11R6/include -I/usr/local/include
 #cgo freebsd openbsd LDFLAGS: -L/usr/X11R6/lib -L/usr/local/lib
-#cgo freebsd openbsd LDFLAGS: -lX11 -lxkbcommon -lxkbcommon-x11 -lX11-xcb -lXcursor -lXfixes
+#cgo netbsd LDFLAGS: -L/usr/X11R7/lib -L/usr/pkg/lib
+#cgo freebsd openbsd netbsd LDFLAGS: -lX11 -lxkbcommon -lxkbcommon-x11 -lX11-xcb -lXcursor -lXfixes
 #cgo linux pkg-config: x11 xkbcommon xkbcommon-x11 x11-xcb xcursor xfixes
 
 #include <stdlib.h>
