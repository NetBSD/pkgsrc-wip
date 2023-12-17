$NetBSD: patch-go.mod,v 1.6 2023/09/07 14:58:16 jperkin Exp $

Use bluge fork to support illumos.
https://github.com/blugelabs/bluge/pull/139

Use apiserver fork to support illumos.
https://github.com/kubernetes/kubernetes/pull/120498

--- go.mod.orig	2023-11-20 09:27:24.000000000 +0000
+++ go.mod
@@ -298,6 +298,7 @@ require (
 	github.com/Masterminds/goutils v1.1.1 // indirect
 	github.com/NYTimes/gziphandler v1.1.1 // indirect
 	github.com/agext/levenshtein v1.2.1 // indirect
+	github.com/blugelabs/ice/v2 v2.0.1 // indirect
 	github.com/alicebob/gopher-json v0.0.0-20200520072559-a9ecdc9d1d3a // indirect
 	github.com/antlr/antlr4/runtime/Go/antlr v1.4.10 // indirect
 	github.com/apapsch/go-jsonmerge/v2 v2.0.0 // indirect
@@ -492,6 +493,10 @@ replace github.com/crewjam/saml => githu
 replace github.com/hashicorp/go-hclog => github.com/hashicorp/go-hclog v0.16.1
 
 // This is a patched v0.8.2 intended to fix session.Find (and others) silently ignoring SQLITE_BUSY errors. This could
+
+replace github.com/blugelabs/bluge => github.com/jperkin/bluge v0.0.0-20221115155924-ffd91b43c395
+
+replace k8s.io/apiserver v0.27.1 => github.com/jperkin/apiserver v0.0.0-20230907131324-edf907a81faa
 // happen, for example, during a read when the sqlite db is under heavy write load.
 // This patch cherry picks compatible fixes from upstream xorm PR#1998 and can be reverted on upgrade to xorm v1.2.0+.
 // This has also been patched to support the azuresql driver that is a thin wrapper for the mssql driver with azure authentication support.
