$NetBSD$

--- rwcancel/select_default.go.orig	2020-03-20 18:00:53.000000000 +0000
+++ rwcancel/select_default.go
@@ -10,5 +10,6 @@ package rwcancel
 import "golang.org/x/sys/unix"
 
 func unixSelect(nfd int, r *unix.FdSet, w *unix.FdSet, e *unix.FdSet, timeout *unix.Timeval) error {
-	return unix.Select(nfd, r, w, e, timeout)
+	var _, err = unix.Select(nfd, r, w, e, timeout)
+	return err
 }
