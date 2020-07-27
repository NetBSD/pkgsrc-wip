$NetBSD$

--- components/webcrypto/algorithms/test_helpers.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ components/webcrypto/algorithms/test_helpers.cc
@@ -25,7 +25,7 @@
 #include "components/webcrypto/status.h"
 #include "third_party/blink/public/platform/web_crypto_algorithm_params.h"
 #include "third_party/blink/public/platform/web_crypto_key_algorithm.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace webcrypto {
 
