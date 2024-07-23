$NetBSD$

Override serial module since we need to patch it.

--- go.mod.orig	2024-07-23 09:34:25.735598236 +0000
+++ go.mod
@@ -2,6 +2,8 @@ module github.com/tinygo-org/tinygo
 
 go 1.19
 
+replace go.bug.st/serial => ../go.bug.st/serial@v1.6.0
+
 require (
 	github.com/aykevl/go-wasm v0.0.2-0.20240312204833-50275154210c
 	github.com/blakesmith/ar v0.0.0-20150311145944-8bd4349a67f2
