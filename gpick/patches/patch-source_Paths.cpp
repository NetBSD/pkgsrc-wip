$NetBSD$

If the choice is between Linux and Windows, choose Linux.

--- source/Paths.cpp.orig	2022-05-08 10:20:36.000000000 +0000
+++ source/Paths.cpp
@@ -36,7 +36,7 @@ struct PathException: std::runtime_error
 		std::runtime_error(message) {
 	}
 };
-#if BOOST_OS_LINUX != 0
+#if 1 != 0
 static std::string getExecutablePath() {
 	std::vector<char> buffer;
 	buffer.resize(4096);
