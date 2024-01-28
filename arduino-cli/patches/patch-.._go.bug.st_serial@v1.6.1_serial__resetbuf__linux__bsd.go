$NetBSD$

--- ../go.bug.st/serial@v1.6.1/serial_resetbuf_linux_bsd.go.orig	2024-01-28 00:48:25.219422094 +0000
+++ ../go.bug.st/serial@v1.6.1/serial_resetbuf_linux_bsd.go
@@ -4,7 +4,7 @@
 // license that can be found in the LICENSE file.
 //
 
-//go:build linux || freebsd || openbsd
+//go:build linux || freebsd || netbsd || openbsd
 
 package serial
 
