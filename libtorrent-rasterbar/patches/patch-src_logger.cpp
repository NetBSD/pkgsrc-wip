$NetBSD: patch-src_logger.cpp,v 1.1 2011/05/11 09:18:46 ryo-on Exp $

* Support Boost 1.46.1

--- src/logger.cpp.orig	2009-02-08 08:13:05.000000000 +0000
+++ src/logger.cpp
@@ -63,7 +63,7 @@ namespace
 	{
 		logger_peer_plugin(std::string const& filename)
 		{
-			fs::path dir(fs::complete("libtorrent_ext_logs"));
+			fs::path dir(fs::absolute("libtorrent_ext_logs"));
 			if (!fs::exists(dir)) fs::create_directories(dir);
 			m_file.open((dir / filename).string().c_str(), std::ios_base::out | std::ios_base::out);
 			m_file << "\n\n\n";
