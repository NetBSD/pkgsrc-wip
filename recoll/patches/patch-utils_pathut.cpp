$NetBSD: patch-utils_pathut.cpp,v 1.1 2012/06/14 07:29:13 thomasklausner Exp $

NetBSD provides statvfs instead of statfs, like Solaris.

--- utils/pathut.cpp.orig	2012-04-27 20:16:14.000000000 +0000
+++ utils/pathut.cpp
@@ -62,7 +62,7 @@ using std::stack;
 
 bool fsocc(const string &path, int *pc, long *blocks)
 {
-#ifdef sun
+#if defined(sun) || defined(__NetBSD__)
     struct statvfs buf;
     if (statvfs(path.c_str(), &buf) != 0) {
 	return false;
@@ -554,7 +554,7 @@ int Pidfile::flopen()
 	return -1;
     }
 
-#ifdef sun
+#if defined(sun) || defined(__NetBSD__)
     struct flock lockdata;
     lockdata.l_start = 0;
     lockdata.l_len = 0;
@@ -576,7 +576,7 @@ int Pidfile::flopen()
 	m_reason = "flock failed";
 	return -1;
     }
-#endif // ! sun
+#endif // ! sun || NetBSD
 
     if (ftruncate(m_fd, 0) != 0) {
 	/* can't happen [tm] */
