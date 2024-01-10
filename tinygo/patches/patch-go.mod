$NetBSD$

Override serial module since we need to patch it.

--- go.mod.orig	2024-01-09 09:27:37.267658129 +0000
+++ go.mod
@@ -2,6 +2,8 @@ module github.com/tinygo-org/tinygo
 
 go 1.18
 
+replace go.bug.st/serial => ../go.bug.st/serial@v1.6.0
+
 require (
 	github.com/aykevl/go-wasm v0.0.2-0.20220616010729-4a0a888aebdc
 	github.com/blakesmith/ar v0.0.0-20150311145944-8bd4349a67f2
