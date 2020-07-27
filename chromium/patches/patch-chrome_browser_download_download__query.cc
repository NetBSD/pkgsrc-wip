$NetBSD$

--- chrome/browser/download/download_query.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/download/download_query.cc
@@ -28,7 +28,7 @@
 #include "components/download/public/common/download_item.h"
 #include "components/url_formatter/url_formatter.h"
 #include "content/public/browser/content_browser_client.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "url/gurl.h"
 
 using download::DownloadDangerType;
