$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/onnx/onnx_importer.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/onnx/onnx_importer.cpp
@@ -4320,15 +4320,15 @@ Mat readTensorFromONNX(const String& path)
 
 #define DNN_PROTOBUF_UNSUPPORTED() CV_Error(Error::StsError, "DNN/ONNX: Build OpenCV with Protobuf to import ONNX models")
 
-Net readNetFromONNX(const String&) {
+Net readNetFromONNX(const String&, int) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
-Net readNetFromONNX(const char*, size_t) {
+Net readNetFromONNX(const char*, size_t, int) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
-Net readNetFromONNX(const std::vector<uchar>&) {
+Net readNetFromONNX(const std::vector<uchar>&, int) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
