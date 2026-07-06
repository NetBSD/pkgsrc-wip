$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/protobuf_io.hpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/protobuf_io.hpp
@@ -87,37 +87,18 @@
 //
 //M*/
 
-#ifndef __OPENCV_DNN_CAFFE_IO_HPP__
-#define __OPENCV_DNN_CAFFE_IO_HPP__
+#ifndef __OPENCV_DNN_PROTOBUF_IO_HPP__
+#define __OPENCV_DNN_PROTOBUF_IO_HPP__
 #ifdef HAVE_PROTOBUF
 
-#if defined(__GNUC__) && __GNUC__ >= 5
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wsuggest-override"
-#endif
-#include "opencv-caffe.pb.h"
-#if defined(__GNUC__) && __GNUC__ >= 5
-#pragma GCC diagnostic pop
-#endif
+#include <cstddef>
 
-namespace caffe { using namespace opencv_caffe; } // avoid massive renames from caffe proto package
+namespace google { namespace protobuf { class Message; class MessageLite; } }
 
 namespace cv {
 namespace dnn {
 
-// Read parameters from a file into a NetParameter proto message.
-void ReadNetParamsFromTextFileOrDie(const char* param_file,
-                                    caffe::NetParameter* param);
-void ReadNetParamsFromBinaryFileOrDie(const char* param_file,
-                                      caffe::NetParameter* param);
-
-// Read parameters from a memory buffer into a NetParammeter proto message.
-void ReadNetParamsFromBinaryBufferOrDie(const char* data, size_t len,
-                                        caffe::NetParameter* param);
-void ReadNetParamsFromTextBufferOrDie(const char* data, size_t len,
-                                      caffe::NetParameter* param);
-
-// Utility functions used internally by Caffe and TensorFlow loaders
+// Utility functions used internally by model loaders
 bool ReadProtoFromTextFile(const char* filename, ::google::protobuf::Message* proto);
 bool ReadProtoFromTextFile(const char* filename, ::google::protobuf::MessageLite* proto);
 bool ReadProtoFromBinaryFile(const char* filename, ::google::protobuf::MessageLite* proto);
