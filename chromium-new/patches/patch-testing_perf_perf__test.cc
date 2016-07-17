$NetBSD$

--- testing/perf/perf_test.cc.orig	2016-06-24 01:02:27.000000000 +0000
+++ testing/perf/perf_test.cc
@@ -2,10 +2,10 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include "testing/perf/perf_test.h"
-
 #include <stdio.h>
 
+#include "testing/perf/perf_test.h"
+
 #include "base/logging.h"
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/stringprintf.h"
