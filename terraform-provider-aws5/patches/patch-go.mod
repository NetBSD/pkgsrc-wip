$NetBSD$

Avoid setting custom godebug, with Go 1.24.x it fails with:

 go: error loading go.mod:
 go.mod:7: unknown godebug "tlskyber"

--- go.mod.orig	2025-06-16 17:29:06.824456336 +0000
+++ go.mod
@@ -4,7 +4,7 @@ go 1.23.10
 
 // Disable experimental post-quantum key exchange mechanism X25519Kyber768Draft00
 // This was causing errors with AWS Network Firewall
-godebug tlskyber=0
+// godebug tlskyber=0
 
 require (
 	github.com/ProtonMail/go-crypto v1.2.0
