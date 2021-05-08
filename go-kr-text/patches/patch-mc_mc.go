$NetBSD$

--- mc/mc.go.orig	2018-05-06 08:24:08.000000000 +0000
+++ mc/mc.go
@@ -10,7 +10,7 @@
 package main
 
 import (
-	"github.com/kr/pty"
+	"github.com/creack/pty"
 	"github.com/kr/text/colwriter"
 	"io"
 	"log"
