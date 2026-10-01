$NetBSD$

Ignore FreeBSD for this file. All other unixes and BSDs seem to
have their Mknod function expect an int for one of the arguments,
but FreeBSD is the odd one out that expects a uint64. I think this
file is just used for tests, so just telling the build to ignore freebsd.

--- internal/rsynctest/rsynctest_unix.go.orig	2026-10-01 05:55:00.176030999 +0000
+++ internal/rsynctest/rsynctest_unix.go
@@ -1,4 +1,4 @@
-//go:build !windows
+//go:build !windows && !freebsd
 
 package rsynctest
 
