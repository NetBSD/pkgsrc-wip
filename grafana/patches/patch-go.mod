$NetBSD: patch-go.mod,v 1.11 2026/08/21 18:04:06 tnn Exp $

module replacements for pkgsrc patches

--- go.mod.orig	2026-11-02 10:58:08.184316900 +0000
+++ go.mod
@@ -728,3 +728,6 @@ exclude k8s.io/client-go v12.0.0+incompatible
 // This was retracted, but seems to be known by the Go module proxy,
 // and is otherwise pulled in as a transitive dependency.
 exclude k8s.io/client-go v12.0.0+incompatible
+
+replace github.com/coreos/go-systemd/v22 => ../github.com/coreos/go-systemd/v22
+replace k8s.io/apiserver => ../k8s.io/apiserver
