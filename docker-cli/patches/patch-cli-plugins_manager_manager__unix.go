$NetBSD$

Honors cli plugins under pkgsrc PREFIX.

--- cli-plugins/manager/manager_unix.go.orig	2025-09-03 20:52:20.000000000 +0000
+++ cli-plugins/manager/manager_unix.go
@@ -13,6 +13,7 @@ package manager
 //
 // [ConfigFile.CLIPluginsExtraDirs]: https://pkg.go.dev/github.com/docker/cli@v26.1.4+incompatible/cli/config/configfile#ConfigFile.CLIPluginsExtraDirs
 var defaultSystemPluginDirs = []string{
+	"@PREFIX@/lib/docker/cli-plugins",
 	"/usr/local/lib/docker/cli-plugins",
 	"/usr/local/libexec/docker/cli-plugins",
 	"/usr/lib/docker/cli-plugins",
