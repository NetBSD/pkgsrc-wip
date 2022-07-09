$NetBSD$

--- vendor/github.com/go-gl/glfw/v3.3/glfw/build.go.orig	2021-12-16 15:57:57.000000000 +0000
+++ vendor/github.com/go-gl/glfw/v3.3/glfw/build.go
@@ -41,13 +41,13 @@ package glfw
 // BSD Build Tags
 // ----------------
 // GLFW Options:
-#cgo freebsd,!wayland openbsd pkg-config: x11 xau xcb xdmcp
+#cgo freebsd,!wayland netbsd openbsd pkg-config: x11 xau xcb xdmcp
 #cgo freebsd,wayland pkg-config: wayland-client wayland-cursor wayland-egl epoll-shim
-#cgo freebsd openbsd CFLAGS: -D_GLFW_HAS_DLOPEN
-#cgo freebsd,!wayland openbsd CFLAGS: -D_GLFW_X11 -D_GLFW_HAS_GLXGETPROCADDRESSARB
+#cgo freebsd netbsd openbsd CFLAGS: -D_GLFW_HAS_DLOPEN
+#cgo freebsd,!wayland netbsd openbsd CFLAGS: -D_GLFW_X11 -D_GLFW_HAS_GLXGETPROCADDRESSARB
 #cgo freebsd,wayland CFLAGS: -D_GLFW_WAYLAND
 
 // Linker Options:
-#cgo freebsd openbsd LDFLAGS: -lm
+#cgo freebsd netbsd openbsd LDFLAGS: -lm
 */
 import "C"
