$NetBSD$

Add NetBSD support via mount_procfs(8)

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- /tmp/pkgsrc/wip/flux2/work/github.com/mitchellh/go-ps@v1.0.0/process_unix_test.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ /tmp/pkgsrc/wip/flux2/work/github.com/mitchellh/go-ps@v1.0.0/process_unix_test.go
@@ -1,4 +1,4 @@
-// +build linux solaris
+// +build linux netbsd solaris
 
 package ps
 
