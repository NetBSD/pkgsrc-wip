$NetBSD$

--- go.mod.orig	2026-08-31 21:07:23.000000000 +0000
+++ go.mod
@@ -30,6 +30,7 @@ require (
 	github.com/BurntSushi/toml v1.4.0 // indirect
 	github.com/chavacava/garif v0.1.0 // indirect
 	github.com/coreos/go-semver v0.3.1 // indirect
+	github.com/creack/goselect v0.1.2 // indirect
 	github.com/docker/libtrust v0.0.0-20160708172513-aabc10ec26b7 // indirect
 	github.com/fatih/color v1.17.0 // indirect
 	github.com/fatih/structtag v1.2.0 // indirect
@@ -50,3 +51,5 @@ require (
 	golang.org/x/mod v0.37.0 // indirect
 	golang.org/x/text v0.38.0 // indirect
 )
+
+replace go.bug.st/serial => github.com/tnn2/go-serial v0.0.0-20240808132751-d345e1ef8d6d
