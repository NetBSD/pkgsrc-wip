$NetBSD: patch-src_downloader.cpp,v 1.1 2014/04/19 08:20:32 thomasklausner Exp $

Fix path to jsoncpp headers.

--- src/downloader.cpp.orig	2014-03-28 08:40:41.000000000 +0000
+++ src/downloader.cpp
@@ -20,7 +20,7 @@
 #include <boost/regex.hpp>
 #include <boost/date_time/posix_time/posix_time_types.hpp>
 #include <tinyxml.h>
-#include <jsoncpp/json/json.h>
+#include <json/json.h>
 #include <htmlcxx/html/ParserDom.h>
 #include <htmlcxx/html/Uri.h>
 
