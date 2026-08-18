$NetBSD$

--- go.mod.orig	2026-08-07 00:43:24.000000000 +0000
+++ go.mod
@@ -579,7 +579,6 @@ require (
 	github.com/munnerz/goautoneg v0.0.0-20191010083416-a7dc8b61c822 // indirect
 	github.com/mxk/go-flowrate v0.0.0-20140419014527-cca7078d478f // indirect
 	github.com/natefinch/wrap v0.2.0 // indirect
-	github.com/ncruces/go-strftime v1.0.0 // indirect
 	github.com/nikunjy/rules v1.5.0 // indirect
 	github.com/oapi-codegen/runtime v1.0.0 // indirect
 	github.com/oasdiff/yaml v0.1.1 // indirect
@@ -618,7 +617,6 @@ require (
 	github.com/quagmt/udecimal v1.9.0 // indirect
 	github.com/redis/go-redis/extra/rediscmd/v9 v9.19.0 // indirect
 	github.com/redis/rueidis v1.0.72 // indirect
-	github.com/remyoudompheng/bigfft v0.0.0-20230129092748-24d4a6f8daec // indirect
 	github.com/rivo/uniseg v0.4.7 // indirect
 	github.com/russross/blackfriday/v2 v2.1.0 // indirect
 	github.com/ryanuber/go-glob v1.0.0 // indirect
@@ -712,9 +710,6 @@ require (
 	gopkg.in/yaml.v3 v3.0.1 // indirect
 	k8s.io/kms v0.36.0 // indirect
 	k8s.io/streaming v0.36.1 // indirect
-	modernc.org/libc v1.72.3 // indirect
-	modernc.org/mathutil v1.7.1 // indirect
-	modernc.org/memory v1.11.0 // indirect
 	modernc.org/sqlite v1.52.0 // indirect
 	sigs.k8s.io/apiserver-network-proxy/konnectivity-client v0.34.0 // indirect
 	sigs.k8s.io/json v0.0.0-20250730193827-2d320260d730 // indirect
@@ -722,6 +717,8 @@ require (
 	software.sslmate.com/src/go-pkcs12 v0.7.2 // indirect
 )
 
+require modernc.org/sqlite/lib v0.0.0-00010101000000-000000000000 // indirect
+
 replace (
 	// Use our fork of dolthub/go-mysql-server which adds TableHintedTable for FOR (...) hints
 	// and makes non-cgo the default for developer builds.
@@ -738,3 +735,9 @@ exclude k8s.io/client-go v12.0.0+incompatible
 // This was retracted, but seems to be known by the Go module proxy, and is
 // otherwise pulled in as a transitive dependency.
 exclude k8s.io/client-go v12.0.0+incompatible
+
+replace modernc.org/sqlite => ./replaced_mods/modernc.org/sqlite
+
+replace modernc.org/sqlite/lib => ./replaced_mods/modernc.org/sqlite/lib
+
+replace github.com/coreos/go-systemd/v22 => ../github.com/coreos/go-systemd/v22
