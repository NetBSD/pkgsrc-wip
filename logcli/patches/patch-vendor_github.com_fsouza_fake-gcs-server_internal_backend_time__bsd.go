$NetBSD$

Add support for NetBSD.

Shared upstream via:

 <https://github.com/fsouza/fake-gcs-server/pull/1989>

--- vendor/github.com/fsouza/fake-gcs-server/internal/backend/time_bsd.go.orig	2025-07-17 17:24:12.781746870 +0000
+++ vendor/github.com/fsouza/fake-gcs-server/internal/backend/time_bsd.go
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-//go:build darwin || freebsd
+//go:build darwin || freebsd || netbsd
 
 package backend
 
