$NetBSD$

Use github.com/mattn/go-sqlite3 instead of modernc.org/sqlite to avoid possible
modernc.org/libc dependency (still not ported on NetBSD).

Via <https://github.com/accurics/terrascan/pull/906/>.

--- go.mod.orig	2021-10-07 15:14:21.000000000 +0000
+++ go.mod
@@ -41,6 +41,7 @@ require (
 	github.com/iancoleman/strcase v0.1.3
 	github.com/itchyny/gojq v0.12.1
 	github.com/mattn/go-isatty v0.0.12
+	github.com/mattn/go-sqlite3 v1.14.6
 	github.com/mitchellh/go-homedir v1.1.0
 	github.com/moby/buildkit v0.8.3
 	github.com/onsi/ginkgo v1.15.1
@@ -66,7 +67,6 @@ require (
 	k8s.io/api v0.21.0
 	k8s.io/apimachinery v0.21.0
 	k8s.io/client-go v10.0.0+incompatible
-	modernc.org/sqlite v1.11.1
 	sigs.k8s.io/kustomize/api v0.8.11
 	sigs.k8s.io/kustomize/kyaml v0.11.0
 )
