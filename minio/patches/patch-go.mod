$NetBSD$

https://github.com/tinylib/msgp/pull/343
https://github.com/containerd/console/pull/84

--- go.mod.orig	2024-05-10 01:41:38.000000000 +0000
+++ go.mod
@@ -83,7 +83,7 @@ require (
 	github.com/secure-io/sio-go v0.3.1
 	github.com/shirou/gopsutil/v3 v3.24.3
 	github.com/tidwall/gjson v1.17.1
-	github.com/tinylib/msgp v1.1.9
+	github.com/tinylib/msgp v1.1.10-0.20240322164430-2236701c6f34
 	github.com/valyala/bytebufferpool v1.0.0
 	github.com/xdg/scram v1.0.5
 	github.com/zeebo/xxh3 v1.0.2
@@ -253,3 +253,5 @@ require (
 	gopkg.in/ini.v1 v1.67.0 // indirect
 	gopkg.in/square/go-jose.v2 v2.6.0 // indirect
 )
+
+replace github.com/containerd/console => github.com/jperkin/console v0.0.0-20240322145618-306df5eeb1d0
