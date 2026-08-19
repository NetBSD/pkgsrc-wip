$NetBSD$

Bump modernc.org/sqlite to 1.53.0 that adds NetBSD/amd64 support.

--- go.mod.orig	2026-08-18 16:39:15.595307650 +0000
+++ go.mod
@@ -32,7 +32,7 @@ require (
 	golang.org/x/sys v0.45.0
 	google.golang.org/api v0.155.0
 	gopkg.in/yaml.v2 v2.4.0
-	modernc.org/sqlite v1.44.3
+	modernc.org/sqlite v1.53.0
 )
 
 require (
@@ -47,7 +47,7 @@ require (
 	github.com/sirupsen/logrus v1.9.3 // indirect
 	golang.org/x/exp v0.0.0-20251023183803-a4bb9ffd2546 // indirect
 	golang.org/x/sync v0.21.0
-	modernc.org/libc v1.67.6 // indirect
+	modernc.org/libc v1.73.4 // indirect
 	modernc.org/mathutil v1.7.1 // indirect
 	modernc.org/memory v1.11.0 // indirect
 )
