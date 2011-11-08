$NetBSD: patch-cpp_src_xtfsutil_xtfsutil__server.cpp,v 1.1 2011/11/08 03:11:32 tnn2 Exp $

--- cpp/src/xtfsutil/xtfsutil_server.cpp.orig	2011-11-03 10:51:07.000000000 +0000
+++ cpp/src/xtfsutil/xtfsutil_server.cpp
@@ -612,7 +612,7 @@ int XtfsUtilServer::getattr(uid_t uid,
   st_buf->st_ctim.tv_nsec = 0;
   st_buf->st_mtim.tv_sec = 0;
   st_buf->st_mtim.tv_nsec = 0;
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__NetBSD__)
   st_buf->st_atimespec.tv_sec = 0;
   st_buf->st_atimespec.tv_nsec = 0;
   st_buf->st_ctimespec.tv_sec = 0;
