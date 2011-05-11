$NetBSD: patch-src_create__torrent.cpp,v 1.1 2011/05/11 09:18:46 ryo-on Exp $

* Support Boost 1.46.1

--- src/create_torrent.cpp.orig	2010-01-19 01:42:35.000000000 +0000
+++ src/create_torrent.cpp
@@ -217,7 +217,7 @@ namespace libtorrent
 					for (fs::path::iterator j = boost::next(i->path.begin());
 						j != i->path.end(); ++j)
 					{
-						path_e.list().push_back(entry(*j));
+						path_e.list().push_back(entry(j->string()));
 					}
 				}
 			}
