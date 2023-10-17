$NetBSD$

--- internal/aghos/os_bsd.go.orig	2023-04-12 13:18:02.000000000 +0000
+++ internal/aghos/os_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || openbsd
+//go:build darwin || openbsd || netbsd
 
 package aghos
 
