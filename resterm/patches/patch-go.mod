$NetBSD$

1.34+ fail on NetBSD with
# modernc.org/sqlite/lib
../.gopath/pkg/mod/modernc.org/sqlite@v1.39.0/lib/sqlite_netbsd_amd64.go:112447:5: mu.enter undefined (type mutex has no field or method enter)
../.gopath/pkg/mod/modernc.org/sqlite@v1.39.0/lib/sqlite_netbsd_amd64.go:112448:11: mu.leave undefined (type mutex has no field or method leave)

--- go.mod.orig	2026-04-19 18:39:26.036701306 +0000
+++ go.mod
@@ -32,7 +32,7 @@ require (
 	k8s.io/api v0.35.1
 	k8s.io/apimachinery v0.35.1
 	k8s.io/client-go v0.35.1
-	modernc.org/sqlite v1.39.0
+	modernc.org/sqlite v1.33.0
 	nhooyr.io/websocket v1.8.7
 )
 
