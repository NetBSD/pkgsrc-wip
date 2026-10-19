$NetBSD$

Prefer pkgsrc's provided files instead of falling back to relative path.

--- galene.go.orig	2026-10-19 21:22:16.070081678 +0000
+++ galene.go
@@ -28,7 +28,7 @@ func main() {
 	var udpRange string
 
 	flag.StringVar(&httpAddr, "http", ":8443", "web server `address`")
-	flag.StringVar(&webserver.StaticRoot, "static", "./static/",
+	flag.StringVar(&webserver.StaticRoot, "static", "@PREFIX@/share/galene/static/",
 		"web server root `directory`")
 	flag.BoolVar(&webserver.Insecure, "insecure", false,
 		"act as an HTTP server rather than HTTPS")
