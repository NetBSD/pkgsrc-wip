$NetBSD$

--- components/autofill/core/browser/form_structure.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/autofill/core/browser/form_structure.cc
@@ -33,7 +33,11 @@
 #include "components/autofill/core/common/form_field_data_predictions.h"
 #include "components/rappor/rappor_service.h"
 #include "components/rappor/rappor_utils.h"
-#include "third_party/re2/src/re2/re2.h"
+#if defined(OS_BSD)
+#  include <re2/re2.h>
+#else
+#  include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace autofill {
 namespace {
