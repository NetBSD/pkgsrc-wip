$NetBSD$

https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f

--- modules/dnn/src/layers/cast2_layer.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/dnn/src/layers/cast2_layer.cpp
@@ -8,8 +8,6 @@
 #include "layers_common.hpp"
 #include "../net_impl.hpp"
 
-#include "opencv-onnx.pb.h"
-
 namespace cv { namespace dnn {
 
 // ONNX Cast operator
@@ -367,21 +365,39 @@ class Cast2LayerImpl CV_FINAL : public Cast2Layer (pri
     bool hasToParam = false;
     int  toCvDepth_ = -1;
 
+    // ONNX TensorProto::DataType values (see opencv-onnx.proto); the 'to'
+    // attribute stores the raw ONNX value. Fixed by the ONNX specification,
+    // duplicated here to keep this layer independent of protobuf-generated headers.
+    enum OnnxDataType
+    {
+        ONNX_DT_FLOAT    = 1,
+        ONNX_DT_UINT8    = 2,
+        ONNX_DT_INT8     = 3,
+        ONNX_DT_UINT16   = 4,
+        ONNX_DT_INT16    = 5,
+        ONNX_DT_INT32    = 6,
+        ONNX_DT_INT64    = 7,
+        ONNX_DT_BOOL     = 9,
+        ONNX_DT_FLOAT16  = 10,
+        ONNX_DT_DOUBLE   = 11,
+        ONNX_DT_BFLOAT16 = 16
+    };
+
     static int mapToCvDepth(int v)
     {
         switch (v)
         {
-            case opencv_onnx::TensorProto_DataType_FLOAT:    return CV_32F;
-            case opencv_onnx::TensorProto_DataType_UINT8:    return CV_8U;
-            case opencv_onnx::TensorProto_DataType_INT8:     return CV_8S;
-            case opencv_onnx::TensorProto_DataType_UINT16:   return CV_16U;
-            case opencv_onnx::TensorProto_DataType_INT16:    return CV_16S;
-            case opencv_onnx::TensorProto_DataType_INT32:    return CV_32S;
-            case opencv_onnx::TensorProto_DataType_INT64:    return CV_64S;
-            case opencv_onnx::TensorProto_DataType_BOOL:     return CV_Bool;
-            case opencv_onnx::TensorProto_DataType_FLOAT16:  return CV_16F;
-            case opencv_onnx::TensorProto_DataType_DOUBLE:   return CV_64F;
-            case opencv_onnx::TensorProto_DataType_BFLOAT16: return CV_16BF;
+            case ONNX_DT_FLOAT:    return CV_32F;
+            case ONNX_DT_UINT8:    return CV_8U;
+            case ONNX_DT_INT8:     return CV_8S;
+            case ONNX_DT_UINT16:   return CV_16U;
+            case ONNX_DT_INT16:    return CV_16S;
+            case ONNX_DT_INT32:    return CV_32S;
+            case ONNX_DT_INT64:    return CV_64S;
+            case ONNX_DT_BOOL:     return CV_Bool;
+            case ONNX_DT_FLOAT16:  return CV_16F;
+            case ONNX_DT_DOUBLE:   return CV_64F;
+            case ONNX_DT_BFLOAT16: return CV_16BF;
             default: break;
         }
 
