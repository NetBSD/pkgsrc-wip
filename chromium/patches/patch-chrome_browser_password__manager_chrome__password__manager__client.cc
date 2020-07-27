$NetBSD$

--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -95,7 +95,7 @@
 #include "net/base/url_util.h"
 #include "net/cert/cert_status_flags.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 #include "url/url_constants.h"
 
 #if BUILDFLAG(FULL_SAFE_BROWSING)
