$NetBSD$

Replace deprecated syscall import to support illumos.
https://github.com/sassoftware/go-rpmutils/pull/32

--- vendor/github.com/sassoftware/go-rpmutils/fileutil/fileutil_unix.go.orig	2024-03-16 16:17:33.922226868 +0000
+++ vendor/github.com/sassoftware/go-rpmutils/fileutil/fileutil_unix.go
@@ -20,12 +20,12 @@ package fileutil
 
 import (
 	"os"
-	"syscall"
+	"golang.org/x/sys/unix"
 )
 
 // HasLinks returns true if the given file has Nlink > 1
 func HasLinks(info os.FileInfo) bool {
-	stat, ok := info.Sys().(*syscall.Stat_t)
+	stat, ok := info.Sys().(*unix.Stat_t)
 	if !ok {
 		return false
 	}
@@ -34,5 +34,5 @@ func HasLinks(info os.FileInfo) bool {
 
 // Mkfifo creates a named pipe with the specified path and permissions
 func Mkfifo(path string, mode uint32) error {
-	return syscall.Mkfifo(path, mode)
+	return unix.Mkfifo(path, mode)
 }
