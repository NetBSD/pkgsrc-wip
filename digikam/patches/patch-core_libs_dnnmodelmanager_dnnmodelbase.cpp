$NetBSD$

OpenCV 5 support.
https://invent.kde.org/graphics/digikam/-/commit/abcadfdc91601fe410c67f4abba87117e81aad3e

--- core/libs/dnnmodelmanager/dnnmodelbase.cpp.orig	2026-06-07 15:07:03.000000000 +0000
+++ core/libs/dnnmodelmanager/dnnmodelbase.cpp
@@ -113,7 +113,9 @@ const QPair<int, int> DNNModelBase::getBackendAndTarge
     const std::map<std::string, int> str2backend
     {
         { "default",     cv::dnn::DNN_BACKEND_DEFAULT          },
+#if OPENCV_TEST_VERSION(5,0,0)
         { "halide",      cv::dnn::DNN_BACKEND_HALIDE           },
+#endif
         { "ie",          cv::dnn::DNN_BACKEND_INFERENCE_ENGINE },
         { "opencv",      cv::dnn::DNN_BACKEND_OPENCV           },
         { "cuda",        cv::dnn::DNN_BACKEND_CUDA             }
