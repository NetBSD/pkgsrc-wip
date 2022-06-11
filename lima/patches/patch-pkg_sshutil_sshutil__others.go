$NetBSD$

err is never defined.

--- pkg/sshutil/sshutil_others.go.orig	2022-05-19 06:28:56.000000000 +0000
+++ pkg/sshutil/sshutil_others.go
@@ -11,6 +11,6 @@ import (
 
 func detectAESAcceleration() bool {
 	const fallback = runtime.GOARCH == "amd64"
-	logrus.WithError(err).Warnf("cannot detect whether AES accelerator is available, assuming %v", fallback)
+	logrus.Warnf("cannot detect whether AES accelerator is available, assuming %v", fallback)
 	return fallback
 }
