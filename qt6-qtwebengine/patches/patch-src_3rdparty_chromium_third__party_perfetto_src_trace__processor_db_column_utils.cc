$NetBSD$

for std::floor and std::ceil on NetBSD   XXXXX

--- src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/utils.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/utils.cc
@@ -14,6 +14,7 @@
  * limitations under the License.
  */
 
+#include "cmath"
 #include "src/trace_processor/db/column/utils.h"
 
 namespace perfetto {
@@ -40,12 +41,12 @@ SearchValidationResult CompareIntColumnW
 
     case FilterOp::kLe:
     case FilterOp::kGt:
-      *sql_val = SqlValue::Long(static_cast<int64_t>(std::floor(double_val)));
+      *sql_val = SqlValue::Long(static_cast<int64_t>(floor(double_val)));
       return SearchValidationResult::kOk;
 
     case FilterOp::kLt:
     case FilterOp::kGe:
-      *sql_val = SqlValue::Long(static_cast<int64_t>(std::ceil(double_val)));
+      *sql_val = SqlValue::Long(static_cast<int64_t>(ceil(double_val)));
       return SearchValidationResult::kOk;
 
     case FilterOp::kIsNotNull:
