$NetBSD$

Add NetBSD to the list of OSes for this file.

--- ipc/uapi_bsd.go.orig	2022-03-17 03:32:14.000000000 +0000
+++ ipc/uapi_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || openbsd
+//go:build darwin || freebsd || openbsd || netbsd
 
 /* SPDX-License-Identifier: MIT
  *
