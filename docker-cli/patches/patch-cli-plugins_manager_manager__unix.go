$NetBSD$

Honors cli plugins under pkgsrc PREFIX.

--- cli-plugins/manager/manager_unix.go.orig	2022-06-06 21:36:39.000000000 +0000
+++ cli-plugins/manager/manager_unix.go
@@ -4,6 +4,7 @@
 package manager
 
 var defaultSystemPluginDirs = []string{
+	"@PREFIX@/lib/docker/cli-plugins",
 	"/usr/local/lib/docker/cli-plugins", "/usr/local/libexec/docker/cli-plugins",
 	"/usr/lib/docker/cli-plugins", "/usr/libexec/docker/cli-plugins",
 }
