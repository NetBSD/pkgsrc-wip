$NetBSD$

Remove Haiku OS type references; not available in odin 26.7.

--- src/server/build.odin.orig	2026-05-01 00:00:00.000000000 +0000
+++ src/server/build.odin
@@ -42,7 +42,6 @@
 	.WASI         = "wasi",
 	.JS           = "js",
 	.Freestanding = "freestanding",
-	.Haiku        = "haiku",
 	.OpenBSD      = "openbsd",
 	.NetBSD       = "netbsd",
 	.Orca         = "orca",
@@ -69,8 +68,6 @@
 	"Freestanding" = .Freestanding,
 	"freestanding" = .Freestanding,
 	"Wasm"         = .JS,
-	"wasm"         = .JS,
-	"Haiku"        = .Haiku,
-	"haiku"        = .Haiku,
+	"wasm"         = .JS,
 	"Openbsd"      = .OpenBSD,
 	"openbsd"      = .OpenBSD,
