$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/ocl4dnn/include/common.hpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/ocl4dnn/include/common.hpp
@@ -41,7 +41,7 @@
 
 #ifndef _OPENCV_LIBDNN_COMMON_HPP_
 #define _OPENCV_LIBDNN_COMMON_HPP_
-#include "../../caffe/glog_emulator.hpp"
+#include "../../glog_emulator.hpp"
 #include <opencv2/core/opencl/runtime/opencl_core.hpp>
 
 // Macro to select the single (_float) or double (_double) precision kernel
