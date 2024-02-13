$NetBSD$

--- go.mod.orig	2023-02-09 08:37:09.000000000 +0000
+++ go.mod
@@ -2,6 +2,8 @@ module github.com/arduino/serial-monitor
 
 go 1.18
 
+replace go.bug.st/serial v1.4.1 => github.com/picohive/go-serial v1.6.1
+
 require (
 	github.com/arduino/pluggable-monitor-protocol-handler v0.9.2
 	go.bug.st/serial v1.4.1
@@ -13,5 +15,5 @@ require (
 	github.com/davecgh/go-spew v1.1.1 // indirect
 	github.com/hashicorp/errwrap v1.1.0 // indirect
 	github.com/hashicorp/go-multierror v1.1.1 // indirect
-	golang.org/x/sys v0.0.0-20220520151302-bc2c85ada10a // indirect
+	golang.org/x/sys v0.0.0-20220829200755-d48e67d00261 // indirect
 )
