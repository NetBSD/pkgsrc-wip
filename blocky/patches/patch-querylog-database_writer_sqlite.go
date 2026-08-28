$NetBSD$

pure-Go SQLite driver is not supported in illumos

--- ./querylog/database_writer_sqlite.go.orig	2026-08-24 21:58:57.738365452 +0000
+++ ./querylog/database_writer_sqlite.go
@@ -1,4 +1,4 @@
-//go:build !mips && !mipsle && !mips64 && !mips64le && !loong64 && !(netbsd && !amd64) && !(openbsd && !amd64 && !arm64)
+//go:build !mips && !mipsle && !mips64 && !mips64le && !loong64 && !(netbsd && !amd64) && !(openbsd && !amd64 && !arm64) && !illumos
 
 // SQLite support is compiled in only on the GOOS/GOARCH targets supported by the
 // pure-Go driver chain (github.com/glebarez/sqlite -> modernc.org/sqlite ->
