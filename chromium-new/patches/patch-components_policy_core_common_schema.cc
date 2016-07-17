$NetBSD$

--- components/policy/core/common/schema.cc.orig	2016-06-24 01:02:18.000000000 +0000
+++ components/policy/core/common/schema.cc
@@ -21,7 +21,11 @@
 #include "components/json_schema/json_schema_constants.h"
 #include "components/json_schema/json_schema_validator.h"
 #include "components/policy/core/common/schema_internal.h"
+#if defined(OS_FREEBSD) || defined(OS_NETBSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
