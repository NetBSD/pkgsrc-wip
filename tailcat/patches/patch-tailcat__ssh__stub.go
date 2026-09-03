$NetBSD$

Enable the built-in SSH and SFTP server on NetBSD; see
patch-tailcat__ssh__unix.go.

--- tailcat_ssh_stub.go.orig	2026-09-03 20:29:37.717350661 +0000
+++ tailcat_ssh_stub.go
@@ -1,7 +1,7 @@
 // Copyright (c) Tailscale Inc & contributors
 // SPDX-License-Identifier: BSD-3-Clause
 
-//go:build ts_omit_ssh || !(linux || darwin || windows)
+//go:build ts_omit_ssh || !(linux || darwin || netbsd || windows)
 
 package tailcat
 
