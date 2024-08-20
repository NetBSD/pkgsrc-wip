$NetBSD$

Honors providers installed via pkgsrc.

--- tfschema/client.go.orig	2024-08-20 14:49:13.868294855 +0000
+++ tfschema/client.go
@@ -161,6 +161,10 @@ func pluginDirs(rootDir string) ([]strin
 	//   Terraform will use ~/.local/share/terraform/plugins,
 	//   /usr/local/share/terraform/plugins, and /usr/share/terraform/plugins.
 
+	// Providers installed via pkgsrc
+	pkgsrcDir := filepath.Join("@PREFIX@", "share/terraform/plugins")
+	dirs = append(dirs, pkgsrcDir)
+
 	// GOPATH
 	// This is not included in the Terraform, but for convenience.
 	gopath := build.Default.GOPATH
