$NetBSD$

Enable the built-in SSH and SFTP server on NetBSD.

The server needs no NetBSD-specific code: creack/pty, u-root/termios and
gliderssh all build on NetBSD, and this file was already the _unix variant.
Only the build constraint kept it out; upstream has no NetBSD CI.

--- tailcat_ssh_unix.go.orig	2026-09-03 20:29:37.662739458 +0000
+++ tailcat_ssh_unix.go
@@ -1,7 +1,7 @@
 // Copyright (c) Tailscale Inc & contributors
 // SPDX-License-Identifier: BSD-3-Clause
 
-//go:build (linux || darwin) && !ts_omit_ssh
+//go:build (linux || darwin || netbsd) && !ts_omit_ssh
 
 package tailcat
 
