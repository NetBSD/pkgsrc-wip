$NetBSD$

--- parsers/regex.go.orig	2019-05-19 09:07:52.000000000 +0000
+++ parsers/regex.go
@@ -4,7 +4,7 @@ import (
 	"bufio"
 	"io"
 
-	"github.com/mvdan/xurls"
+	"mvdan.cc/xurls/v2"
 )
 
 type RegexParser struct{}
