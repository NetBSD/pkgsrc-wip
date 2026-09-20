$NetBSD$

* Add NetBSD support
* Portable initializing of struct flock

--- src/core/logging.cpp.orig	2026-09-19 12:01:40.484371465 +0000
+++ src/core/logging.cpp
@@ -32,7 +32,7 @@
 #include <sys/sendfile.h>
 #include <sys/types.h>
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 
@@ -472,13 +472,12 @@ void ThreadLogging::initFs() {
 		delete detailedFile;
 		detailedFile = nullptr;
 	} else {
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
 
 		if (fcntl(detailedFile->handle(), F_SETLK, &lock) != 0) { // NOLINT
 			qCWarning(logLogging) << "Unable to set lock marker on detailed log file. --follow from "
@@ -976,13 +975,12 @@ bool LogReader::continueReading() {
 }
 
 void LogFollower::FcntlWaitThread::run() {
-	struct flock lock = {
-	    .l_type = F_RDLCK, // won't block other read locks when we take it
-	    .l_whence = SEEK_SET,
-	    .l_start = 0,
-	    .l_len = 0,
-	    .l_pid = 0,
-	};
+	struct flock lock = {};
+	lock.l_type = F_RDLCK; // won't block other read locks when we take it
+	lock.l_whence = SEEK_SET;
+	lock.l_start = 0;
+	lock.l_len = 0;
+	lock.l_pid = 0;
 
 	auto r = fcntl(this->follower->reader->file->handle(), F_SETLKW, &lock); // NOLINT
 
