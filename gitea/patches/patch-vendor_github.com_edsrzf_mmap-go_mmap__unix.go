$NetBSD$

--- vendor/github.com/edsrzf/mmap-go/mmap_unix.go.orig	2018-08-10 17:16:53.000000000 +0000
+++ vendor/github.com/edsrzf/mmap-go/mmap_unix.go
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build darwin dragonfly freebsd linux openbsd solaris netbsd
+// +build darwin dragonfly freebsd linux openbsd !solaris netbsd
 
 package mmap
 
