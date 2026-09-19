$NetBSD$

--- src/core/paths.cpp.orig	2026-09-19 11:55:45.119463273 +0000
+++ src/core/paths.cpp
@@ -361,13 +361,12 @@ void QsPaths::createLock() {
 			return;
 		}
 
-		struct flock lock = {
-		    .l_type = F_WRLCK,
-		    .l_whence = SEEK_SET,
-		    .l_start = 0,
-		    .l_len = 0,
-		    .l_pid = 0,
-		};
+		struct flock lock = {};
+		lock.l_type = F_WRLCK;
+		lock.l_whence = SEEK_SET;
+		lock.l_start = 0;
+		lock.l_len = 0;
+		lock.l_pid = 0;
 
 		if (fcntl(file->handle(), F_SETLK, &lock) != 0) { // NOLINT
 			qCCritical(logPaths).nospace() << "Could not lock instance lock at " << path
@@ -389,13 +388,12 @@ bool QsPaths::checkLock(const QString& p
 	auto file = QFile(QDir(path).filePath("instance.lock"));
 	if (!file.open(QFile::ReadOnly)) return false;
 
-	struct flock lock = {
-	    .l_type = F_WRLCK,
-	    .l_whence = SEEK_SET,
-	    .l_start = 0,
-	    .l_len = 0,
-	    .l_pid = 0,
-	};
+	struct flock lock = {};
+	lock.l_type = F_WRLCK;
+	lock.l_whence = SEEK_SET;
+	lock.l_start = 0;
+	lock.l_len = 0;
+	lock.l_pid = 0;
 
 	fcntl(file.handle(), F_GETLK, &lock); // NOLINT
 	auto isLocked = lock.l_type != F_UNLCK;
