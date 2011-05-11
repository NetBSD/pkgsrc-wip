$NetBSD: patch-include_libtorrent_debug.hpp,v 1.1 2011/05/11 09:18:46 ryo-on Exp $

* Support Boost 1.46.1

--- include/libtorrent/debug.hpp.orig	2008-10-05 01:41:54.000000000 +0000
+++ include/libtorrent/debug.hpp
@@ -64,7 +64,7 @@ namespace libtorrent
 			try
 			{
 #endif
-				fs::path dir(fs::complete(logpath / ("libtorrent_logs" + boost::lexical_cast<std::string>(instance))));
+				fs::path dir(fs::absolute(logpath / ("libtorrent_logs" + boost::lexical_cast<std::string>(instance))));
 				if (!fs::exists(dir)) fs::create_directories(dir);
 				m_file.open((dir / filename).string().c_str(), std::ios_base::out | (append ? std::ios_base::app : std::ios_base::out));
 				*this << "\n\n\n*** starting log ***\n";
