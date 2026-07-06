$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/tensorflow/tf_importer.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/tensorflow/tf_importer.cpp
@@ -3373,15 +3373,15 @@ void writeTextGraph(const String& _model, const String
 
 #define DNN_PROTOBUF_UNSUPPORTED() CV_Error(Error::StsError, "DNN/TF: Build OpenCV with Protobuf to import TensorFlow models")
 
-Net readNetFromTensorflow(const String &, const String &) {
+Net readNetFromTensorflow(const String &, const String &, int, const std::vector<String>&) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
-Net readNetFromTensorflow(const char*, size_t, const char*, size_t) {
+Net readNetFromTensorflow(const char*, size_t, const char*, size_t, int, const std::vector<String>&) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
-Net readNetFromTensorflow(const std::vector<uchar>&, const std::vector<uchar>&) {
+Net readNetFromTensorflow(const std::vector<uchar>&, const std::vector<uchar>&, int, const std::vector<String>&) {
     DNN_PROTOBUF_UNSUPPORTED();
 }
 
