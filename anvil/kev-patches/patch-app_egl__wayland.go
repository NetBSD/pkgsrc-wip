$NetBSD$

--- app/egl_wayland.go.orig	2024-11-19 02:51:06.267655825 +0000
+++ app/egl_wayland.go
@@ -16,7 +16,7 @@ import (
 
 /*
 #cgo linux pkg-config: egl wayland-egl
-#cgo freebsd openbsd LDFLAGS: -lwayland-egl
+#cgo freebsd openbsd netbsd LDFLAGS: -lwayland-egl
 #cgo CFLAGS: -DEGL_NO_X11
 
 #include <EGL/egl.h>
