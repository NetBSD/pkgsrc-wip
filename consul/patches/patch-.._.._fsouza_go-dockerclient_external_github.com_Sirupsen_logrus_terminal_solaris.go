$NetBSD$

Rudimentary SunOS support based on community patches by @MerlinDMC.

https://github.com/hashicorp/consul/issues/159

--- ../../fsouza/go-dockerclient/external/github.com/Sirupsen/logrus/terminal_solaris.go.orig	2015-12-17 12:43:25.130991954 +0000
+++ ../../fsouza/go-dockerclient/external/github.com/Sirupsen/logrus/terminal_solaris.go
@@ -0,0 +1,14 @@
+// Based on ssh/terminal:
+// Copyright 2011 The Go Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+// +build solaris
+
+package logrus
+
+// IsTerminal returns true if the given file descriptor is a terminal.
+// Since the needed syscalls are mising on Illumos/Solaris we're just returning false here
+func IsTerminal() bool {
+       return false
+}
