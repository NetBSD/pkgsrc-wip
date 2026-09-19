$NetBSD$

--- src/core/toolsupport.cpp.orig	2026-09-19 12:08:24.218435891 +0000
+++ src/core/toolsupport.cpp
@@ -54,13 +54,12 @@ bool QmlToolingSupport::lockTooling() {
 		return false;
 	}
 
-	struct flock lock = {
-	    .l_type = F_WRLCK,
-	    .l_whence = SEEK_SET, // NOLINT (fcntl.h??)
-	    .l_start = 0,
-	    .l_len = 0,
-	    .l_pid = 0,
-	};
+	struct flock lock = {};
+	lock.l_type = F_WRLCK;
+	lock.l_whence = SEEK_SET; // NOLINT (fcntl.h??)
+	lock.l_start = 0;
+	lock.l_len = 0;
+	lock.l_pid = 0;
 
 	if (fcntl(file->handle(), F_SETLK, &lock) == 0) {
 		qCInfo(logTooling) << "Acquired tooling support lock";
