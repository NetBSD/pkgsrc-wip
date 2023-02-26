$NetBSD$

Use latest pebble version that supports NetBSD.

--- go.mod.orig	2023-02-26 00:21:23.660885572 +0000
+++ go.mod
@@ -42,7 +42,7 @@ require (
 	github.com/golang/snappy v0.0.4 // indirect
 	github.com/gorilla/css v1.0.0 // indirect
 	github.com/json-iterator/go v1.1.12 // indirect
-	github.com/klauspost/compress v1.15.13 // indirect
+	github.com/klauspost/compress v1.15.15 // indirect
 	github.com/kr/pretty v0.3.1 // indirect
 	github.com/kr/text v0.2.0 // indirect
 	github.com/matttproud/golang_protobuf_extensions v1.0.4 // indirect
@@ -90,3 +90,5 @@ require (
 	gopkg.in/ini.v1 v1.67.0 // indirect
 	gopkg.in/yaml.v3 v3.0.1 // indirect
 )
+
+replace github.com/cockroachdb/pebble => github.com/cockroachdb/pebble v0.0.0-20230223225144-bc4c9afe47a5
