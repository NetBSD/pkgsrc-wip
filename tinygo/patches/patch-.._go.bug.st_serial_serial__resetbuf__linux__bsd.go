$NetBSD$

add NetBSD support

--- ../go.bug.st/serial@v1.6.0/serial_resetbuf_linux_bsd.go.orig	2024-01-09 09:15:27.333184302 +0000
+++ ../go.bug.st/serial@v1.6.0/serial_resetbuf_linux_bsd.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || freebsd || openbsd
+//go:build linux || freebsd || openbsd || netbsd
 
 package serial
 
