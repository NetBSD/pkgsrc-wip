$NetBSD$

Add NetBSD support via mount_procfs(8)

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- ../github.com/mitchellh/go-ps@v1.0.0/process_unix.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ ../github.com/mitchellh/go-ps@v1.0.0/process_unix.go
@@ -1,4 +1,4 @@
-// +build linux solaris
+// +build linux netbsd solaris
 
 package ps
 
