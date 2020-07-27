$NetBSD$

--- extensions/browser/api/web_request/form_data_parser.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ extensions/browser/api/web_request/form_data_parser.cc
@@ -16,7 +16,7 @@
 #include "base/values.h"
 #include "net/base/escape.h"
 #include "net/http/http_request_headers.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using base::DictionaryValue;
 using base::ListValue;
