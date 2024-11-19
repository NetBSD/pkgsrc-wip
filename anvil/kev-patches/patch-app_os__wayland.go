$NetBSD$

--- app/os_wayland.go.orig	2024-11-19 02:51:06.279008507 +0000
+++ app/os_wayland.go
@@ -51,7 +51,7 @@ import (
 
 /*
 #cgo linux pkg-config: wayland-client wayland-cursor
-#cgo freebsd openbsd LDFLAGS: -lwayland-client -lwayland-cursor
+#cgo freebsd openbsd netbsd LDFLAGS: -lwayland-client -lwayland-cursor
 #cgo freebsd CFLAGS: -I/usr/local/include
 #cgo freebsd LDFLAGS: -L/usr/local/lib
 
