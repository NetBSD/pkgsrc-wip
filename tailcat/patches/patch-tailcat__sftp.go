$NetBSD$

Enable the built-in SSH and SFTP server on NetBSD; see
patch-tailcat__ssh__unix.go.

--- tailcat_sftp.go.orig	2026-09-03 20:29:37.699223720 +0000
+++ tailcat_sftp.go
@@ -1,7 +1,7 @@
 // Copyright (c) Tailscale Inc & contributors
 // SPDX-License-Identifier: BSD-3-Clause
 
-//go:build (linux || darwin || windows) && !ts_omit_ssh
+//go:build (linux || darwin || netbsd || windows) && !ts_omit_ssh
 
 package tailcat
 
