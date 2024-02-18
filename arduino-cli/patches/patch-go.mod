$NetBSD$

--- go.mod.orig	2024-01-28 00:36:42.886410216 +0000
+++ go.mod
@@ -4,6 +4,7 @@ go 1.21
 
 // We must use this fork until https://github.com/mailru/easyjson/pull/372 is merged
 replace github.com/mailru/easyjson => github.com/cmaglie/easyjson v0.8.1
+replace go.bug.st/serial v1.6.1 => github.com/picohive/go-serial v1.6.2
 
 require (
 	github.com/ProtonMail/go-crypto v0.0.0-20230828082145-3c4c8a2d2371
