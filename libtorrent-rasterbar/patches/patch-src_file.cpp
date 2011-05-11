$NetBSD: patch-src_file.cpp,v 1.1 2011/05/11 09:18:46 ryo-on Exp $

* Support Boost 1.46.1

--- src/file.cpp.orig	2010-02-14 04:05:22.000000000 +0000
+++ src/file.cpp
@@ -207,7 +207,7 @@ namespace libtorrent
 			| S_IRGRP | S_IWGRP
 			| S_IROTH | S_IWOTH;
 
-		m_fd = ::open(path.external_file_string().c_str()
+		m_fd = ::open(path.native().c_str()
 			, map_open_mode(mode.m_mask), permissions);
 
 		if (m_fd == -1)
