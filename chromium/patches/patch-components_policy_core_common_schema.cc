$NetBSD$

--- components/policy/core/common/schema.cc.orig	2020-07-08 21:40:40.000000000 +0000
+++ components/policy/core/common/schema.cc
@@ -24,7 +24,7 @@
 #include "base/strings/stringprintf.h"
 #include "components/policy/core/common/json_schema_constants.h"
 #include "components/policy/core/common/schema_internal.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace schema = json_schema_constants;
 
