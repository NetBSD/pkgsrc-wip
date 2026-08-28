$NetBSD$

pure-Go SQLite driver is not supported in illumos

--- ./querylog/database_writer_sqlite_unsupported.go.orig	2026-08-24 21:58:40.371113197 +0000
+++ ./querylog/database_writer_sqlite_unsupported.go
@@ -1,4 +1,4 @@
-//go:build mips || mipsle || mips64 || mips64le || loong64 || (netbsd && !amd64) || (openbsd && !amd64 && !arm64)
+//go:build mips || mipsle || mips64 || mips64le || loong64 || (netbsd && !amd64) || (openbsd && !amd64 && !arm64) || illumos
 
 // This is the exact complement of the constraint in database_writer_sqlite.go: the
 // GOOS/GOARCH targets where the pure-Go SQLite driver chain (github.com/glebarez/
