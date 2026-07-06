$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/tensorflow/tf_io.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/tensorflow/tf_io.cpp
@@ -25,8 +25,8 @@ Implementation of various functions which are related 
 
 #include "tf_io.hpp"
 
-#include "../caffe/caffe_io.hpp"
-#include "../caffe/glog_emulator.hpp"
+#include "../protobuf_io.hpp"
+#include "../glog_emulator.hpp"
 
 namespace cv {
 namespace dnn {
