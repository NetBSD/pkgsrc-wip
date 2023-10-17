$NetBSD$

--- internal/aghos/user_unix.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/aghos/user_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || linux || openbsd
+//go:build darwin || freebsd || linux || openbsd || netbsd
 
 package aghos
 
