$NetBSD$

Honors providers installed via pkgsrc.

--- provider_source.go.orig	2021-03-24 18:39:36.000000000 +0000
+++ provider_source.go
@@ -160,6 +160,9 @@ func implicitProviderSource(services *di
 		addLocalDir(dir)
 	}
 
+	// Providers installed via pkgsrc
+	addLocalDir(filepath.Join("@PREFIX@", "share/terraform/plugins"))
+
 	// Anything we found in local directories above is excluded from being
 	// looked up via the registry source we're about to construct.
 	var directExcluded getproviders.MultiSourceMatchingPatterns
