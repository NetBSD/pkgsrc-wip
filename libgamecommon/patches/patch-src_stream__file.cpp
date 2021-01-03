$NetBSD$

Fix call of strerror_r(3), returns an int, not a (char*).

--- src/stream_file.cpp.orig	2015-02-20 11:37:06.000000000 +0000
+++ src/stream_file.cpp
@@ -37,7 +37,7 @@ inline std::string strerror_str(int errn
 #ifdef WIN32
 	strerror_s(buf, sizeof(buf), errno2);
 #else
-	pbuf = strerror_r(errno2, buf, sizeof(buf));
+	errno = strerror_r(errno2, buf, sizeof(buf));
 #endif
 	if (errno != 0) {
 		return createString("[unable to get message for error code " << errno2
