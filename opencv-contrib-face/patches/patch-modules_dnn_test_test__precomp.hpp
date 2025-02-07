$NetBSD: patch-modules_dnn_test__precomp.hpp,v 1.1 2019/04/29 03:23:53 mef Exp $

adhoc patch to build 3.4.6

[ 30%] Built target opencv_core
/export/WRKOBJDIR/graphics/opencv/work/opencv-3.4.6/build/modules/dnn/test_precomp.hpp:50:10: fatal error: test/test_common.hpp: No such file or directory
 #include "test/test_common.hpp"
          ^~~~~~~~~~~~~~~~~~~~~~
compilation terminated.

--- modules/dnn/test/test_precomp.hpp.orig	2025-01-08 12:47:46.000000000 +0000
+++ modules/dnn/test/test_precomp.hpp
@@ -48,6 +48,6 @@
 #include "opencv2/core/utils/configuration.private.hpp"
 
 #include "opencv2/dnn.hpp"
-#include "test_common.hpp"
+#include "../test/test_common.hpp"
 
 #endif
