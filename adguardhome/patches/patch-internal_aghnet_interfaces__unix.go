$NetBSD$

--- internal/aghnet/interfaces_unix.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/aghnet/interfaces_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || openbsd
+//go:build darwin || freebsd || openbsd || netbsd
 
 package aghnet
 
