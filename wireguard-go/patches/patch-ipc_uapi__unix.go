$NetBSD$

Support NetBSD.

--- ipc/uapi_unix.go.orig	2022-06-07 07:27:04.052864036 +0000
+++ ipc/uapi_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || openbsd || netbsd
 
 /* SPDX-License-Identifier: MIT
  *
