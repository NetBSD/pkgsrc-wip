$NetBSD$

Use latest pebble version that supports NetBSD.

Different version of it shared and merged upstream via:

 <https://github.com/projectdiscovery/httpx/pull/1018>

...and should be no longer needed in httpx-1.2.8.

--- go.mod.orig	2023-02-24 18:27:49.534397278 +0000
+++ go.mod
@@ -123,3 +123,5 @@ require (
 	gopkg.in/ini.v1 v1.67.0 // indirect
 	gopkg.in/yaml.v3 v3.0.1 // indirect
 )
+
+replace github.com/cockroachdb/pebble => github.com/cockroachdb/pebble v0.0.0-20230223225144-bc4c9afe47a5
