$NetBSD$

OpenCV 5 support.
https://invent.kde.org/graphics/digikam/-/commit/abcadfdc91601fe410c67f4abba87117e81aad3e

--- core/libs/qtopencvimg/qtopencvimg.cpp.orig	2026-06-07 15:07:03.000000000 +0000
+++ core/libs/qtopencvimg/qtopencvimg.cpp
@@ -97,7 +97,7 @@ cv::Mat QtOpenCVImg::adjustChannelsOrder(const cv::Mat
         {
             // BGRA <==> RBGA
 
-            cv::cvtColor(srcMat, desMat, CV_BGRA2RGBA);
+            cv::cvtColor(srcMat, desMat, cv::ColorConversionCodes::COLOR_BGRA2RGBA);
         }
     }
     catch (cv::Exception& e)
@@ -279,11 +279,11 @@ cv::Mat QtOpenCVImg::image2Mat(const DImg& img, int re
                 {
                     if      (MCO_RGB == requiredOrder)
                     {
-                        cv::cvtColor(mat0, mat0, CV_RGBA2GRAY);
+                        cv::cvtColor(mat0, mat0, cv::ColorConversionCodes::COLOR_RGBA2GRAY);
                     }
                     else if (MCO_BGR == requiredOrder)
                     {
-                        cv::cvtColor(mat0, mat0, CV_BGRA2GRAY);
+                        cv::cvtColor(mat0, mat0, cv::ColorConversionCodes::COLOR_BGRA2GRAY);
                     }
 
                     break;
@@ -292,11 +292,11 @@ cv::Mat QtOpenCVImg::image2Mat(const DImg& img, int re
                 {
                     if      (MCO_RGB == requiredOrder)
                     {
-                        cv::cvtColor(mat0, mat0, CV_RGBA2RGB);
+                        cv::cvtColor(mat0, mat0, cv::ColorConversionCodes::COLOR_RGBA2RGB);
                     }
                     else if (MCO_BGR == requiredOrder)
                     {
-                        cv::cvtColor(mat0, mat0, CV_BGRA2BGR);
+                        cv::cvtColor(mat0, mat0, cv::ColorConversionCodes::COLOR_BGRA2BGR);
                     }
 
                     break;
@@ -364,21 +364,21 @@ cv::Mat QtOpenCVImg::image2Mat(const QImage& img, int 
             {
                 if      (mat0.channels() == 3)
                 {
-                    cv::cvtColor(mat0, mat_adjustCn, CV_RGB2GRAY);
+                    cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_RGB2GRAY);
                 }
                 else if (mat0.channels() == 4)
                 {
                     if      (srcOrder == MCO_BGRA)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_BGRA2GRAY);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_BGRA2GRAY);
                     }
                     else if (srcOrder == MCO_RGBA)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_RGBA2GRAY);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_RGBA2GRAY);
                     }
                     else    // MCO_ARGB
                     {
-                        cv::cvtColor(argb2bgra(mat0), mat_adjustCn, CV_BGRA2GRAY);
+                        cv::cvtColor(argb2bgra(mat0), mat_adjustCn, cv::ColorConversionCodes::COLOR_BGRA2GRAY);
                     }
                 }
 
@@ -389,13 +389,13 @@ cv::Mat QtOpenCVImg::image2Mat(const QImage& img, int 
             {
                 if      (mat0.channels() == 1)
                 {
-                    cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? CV_GRAY2BGR : CV_GRAY2RGB));
+                    cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? cv::ColorConversionCodes::COLOR_GRAY2BGR : cv::ColorConversionCodes::COLOR_GRAY2RGB));
                 }
                 else if (mat0.channels() == 3)
                 {
                     if (requriedOrder != srcOrder)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_RGB2BGR);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_RGB2BGR);
                     }
                 }
 
@@ -410,11 +410,11 @@ cv::Mat QtOpenCVImg::image2Mat(const QImage& img, int 
                     }
                     else if (srcOrder == MCO_BGRA)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? CV_BGRA2BGR : CV_BGRA2RGB));
+                        cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? cv::ColorConversionCodes::COLOR_BGRA2BGR : cv::ColorConversionCodes::COLOR_BGRA2RGB));
                     }
                     else    // RGBA
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? CV_RGBA2BGR : CV_RGBA2RGB));
+                        cv::cvtColor(mat0, mat_adjustCn, ((requriedOrder == MCO_BGR) ? cv::ColorConversionCodes::COLOR_RGBA2BGR : cv::ColorConversionCodes::COLOR_RGBA2RGB));
                     }
                 }
 
@@ -435,11 +435,11 @@ cv::Mat QtOpenCVImg::image2Mat(const QImage& img, int 
                     }
                     else if (requriedOrder == MCO_RGBA)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_GRAY2RGBA);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_GRAY2RGBA);
                     }
                     else    // MCO_BGRA
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_GRAY2BGRA);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_GRAY2BGRA);
                     }
                 }
                 else if (mat0.channels() == 3)
@@ -454,11 +454,11 @@ cv::Mat QtOpenCVImg::image2Mat(const QImage& img, int 
                     }
                     else if (requriedOrder == MCO_RGBA)
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_RGB2RGBA);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_RGB2RGBA);
                     }
                     else    // MCO_BGRA
                     {
-                        cv::cvtColor(mat0, mat_adjustCn, CV_RGB2BGRA);
+                        cv::cvtColor(mat0, mat_adjustCn, cv::ColorConversionCodes::COLOR_RGB2BGRA);
                     }
                 }
                 else if (mat0.channels() == 4)
@@ -560,14 +560,14 @@ QImage QtOpenCVImg::mat2Image(const cv::Mat& mat, MatC
 
             if (order == MCO_BGR)
             {
-                cv::cvtColor(mat, mat_adjustCn, CV_BGR2RGB);
+                cv::cvtColor(mat, mat_adjustCn, cv::ColorConversionCodes::COLOR_BGR2RGB);
             }
 
 #else
 
             format = QImage::Format_RGB32;
             cv::Mat mat_tmp;
-            cv::cvtColor(mat, mat_tmp, ((order == MCO_BGR) ? CV_BGR2BGRA : CV_RGB2BGRA));
+            cv::cvtColor(mat, mat_tmp, ((order == MCO_BGR) ? cv::ColorConversionCodes::COLOR_BGR2BGRA : cv::ColorConversionCodes::COLOR_RGB2BGRA));
 
 #   if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
 
