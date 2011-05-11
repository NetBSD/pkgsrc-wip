$NetBSD: patch-src_torrent__info.cpp,v 1.1 2011/05/11 09:18:46 ryo-on Exp $

* Support Boost 1.46.1

--- src/torrent_info.cpp.orig	2009-11-28 09:43:38.000000000 +0000
+++ src/torrent_info.cpp
@@ -199,8 +199,8 @@ namespace libtorrent
 		fs::path new_path;
 		for (fs::path::const_iterator i = p.begin(); i != p.end(); ++i)
 		{
-			if (!valid_path_element(*i)) continue;
-			new_path /= *i;
+			if (!valid_path_element(i->string())) continue;
+			new_path /= i->string();
 		}
 		TORRENT_ASSERT(!new_path.is_complete());
 		return new_path;
