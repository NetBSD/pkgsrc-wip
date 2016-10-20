$NetBSD$

--- build/version_info_netbsd.sh.orig	2016-10-20 01:46:08.880514594 +0000
+++ build/version_info_netbsd.sh
@@ -0,0 +1,32 @@
+#!/bin/sh
+#
+# Copyright (c) 2005-2016 Intel Corporation
+#
+# Licensed under the Apache License, Version 2.0 (the "License");
+# you may not use this file except in compliance with the License.
+# You may obtain a copy of the License at
+#
+#     http://www.apache.org/licenses/LICENSE-2.0
+#
+# Unless required by applicable law or agreed to in writing, software
+# distributed under the License is distributed on an "AS IS" BASIS,
+# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+# See the License for the specific language governing permissions and
+# limitations under the License.
+#
+#
+#
+#
+
+# Script used to generate version info string
+echo "#define __TBB_VERSION_STRINGS(N) \\"
+echo '#N": BUILD_HOST'"\t\t"`hostname -s`" ("`uname -m`")"'" ENDL \'
+echo '#N": BUILD_OS'"\t\t"`uname -sr`'" ENDL \'
+echo '#N": BUILD_KERNEL'"\t"`uname -r`'" ENDL \'
+echo '#N": BUILD_GCC'"\t\t"`${CXX} -dumpversion`'" ENDL \'
+[ -z "$COMPILER_VERSION" ] || echo '#N": BUILD_COMPILER'"\t"$COMPILER_VERSION'" ENDL \'
+echo '#N": BUILD_LD'"\t\t"`ld -v 2>&1 | head -n 1`'" ENDL \'
+echo '#N": BUILD_TARGET'"\t$arch on $runtime"'" ENDL \'
+echo '#N": BUILD_COMMAND'"\t"$*'" ENDL \'
+echo ""
+echo "#define __TBB_DATETIME \""`date -u`"\""
