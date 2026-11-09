$NetBSD$

OpenCV 5 support.
https://invent.kde.org/graphics/digikam/-/commit/abcadfdc91601fe410c67f4abba87117e81aad3e

--- core/libs/dimg/filters/nr/nrestimate.cpp.orig	2026-06-07 15:07:03.000000000 +0000
+++ core/libs/dimg/filters/nr/nrestimate.cpp
@@ -115,7 +115,7 @@ void NREstimate::startAnalyse()
     readImage();
     postProgress(5);
 
-    //--convert fimg to CvMat*-------------------------------------------------------------------------------
+    //--convert fimg to Cv::Mat*-------------------------------------------------------------------------------
 
     // convert the image into YCrCb color model
 
@@ -123,15 +123,15 @@ void NREstimate::startAnalyse()
 
     // One dimensional CvMat which stores the image
 
-    CvMat* points    = cvCreateMat(m_orgImage.numPixels(), 3, CV_32FC1);
+    cv::Mat points    = cv::Mat(m_orgImage.numPixels(), 3, CV_32FC1);
 
     // matrix to store the index of the clusters
 
-    CvMat* clusters  = cvCreateMat(m_orgImage.numPixels(), 1, CV_32SC1);
+    cv::Mat clusters  = cv::Mat(m_orgImage.numPixels(), 1, CV_32SC1);
 
     // pointer variable to handle the CvMat* points (the image in CvMat format)
 
-    float* pointsPtr = reinterpret_cast<float*>(points->data.ptr);
+    float* pointsPtr = reinterpret_cast<float*>(points.data);
 
     for (uint x = 0 ; runningFlag() && (x < m_orgImage.numPixels()) ; ++x)
     {
@@ -141,19 +141,15 @@ void NREstimate::startAnalyse()
         }
     }
 
-    // Array to store the centers of the clusters
-
-    CvArr* centers = nullptr;
-
     qCDebug(DIGIKAM_DIMG_LOG) << "Everything ready for the cvKmeans2 or as it seems to";
     postProgress(10);
 
     //-- KMEANS ---------------------------------------------------------------------------------------------
 
-    cvKMeans2(points, d->clusterCount, clusters,
-              cvTermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0), 3, nullptr, 0, centers, nullptr);
+    cv::kmeans(points, d->clusterCount, clusters,
+              cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 10, 1.0), 3, cv::KMEANS_PP_CENTERS);
 
-    qCDebug(DIGIKAM_DIMG_LOG) << "cvKmeans2 successfully run";
+    qCDebug(DIGIKAM_DIMG_LOG) << "cv::kmeans successfully run";
     postProgress(15);
 
     //-- Divide into cluster->columns, sample->rows, in matrix standard deviation ---------------------------
@@ -174,7 +170,7 @@ void NREstimate::startAnalyse()
 
     for (uint i = 0 ; runningFlag() && (i < m_orgImage.numPixels()) ; ++i)
     {
-        columnIndex = clusters->data.i[i];
+        columnIndex = clusters.at<int>(i);
         rowPosition[columnIndex]++;
     }
 
@@ -210,7 +206,7 @@ void NREstimate::startAnalyse()
 
     //-- Divide and conquer ---------------------------------------------------------------------------------
 
-    CvMat* sd = cvCreateMat(max, (d->clusterCount * points->cols), CV_32FC1);
+    cv::Mat sd = cv::Mat(max, (d->clusterCount * points.cols), CV_32FC1);
 
     postProgress(30);
 
@@ -230,26 +226,26 @@ void NREstimate::startAnalyse()
 
     for (uint i = 0 ; runningFlag() && (i < m_orgImage.numPixels()) ; ++i)
     {
-        columnIndex = clusters->data.i[i];
+        columnIndex = clusters.at<int>(i);
         rowIndex    = rPosition[columnIndex];
 
         // moving to the right row
 
-        ptr         = reinterpret_cast<float*>(sd->data.ptr + rowIndex*(sd->step));
+        ptr         = reinterpret_cast<float*>(sd.data + rowIndex*(sd.step));
 
         // moving to the right column
 
         for (int j = 0 ; runningFlag() && (j < columnIndex) ; ++j)
         {
-            for (int z = 0 ; runningFlag() && (z < (points->cols)) ; ++z)
+            for (int z = 0 ; runningFlag() && (z < (points.cols)) ; ++z)
             {
                 ptr++;
             }
         }
 
-        for (int z = 0 ; runningFlag() && (z < (points->cols)) ; ++z)
+        for (int z = 0 ; runningFlag() && (z < (points.cols)) ; ++z)
         {
-            *ptr++ = cvGet2D(points, i, z).val[0];
+            *ptr++ = points.at<float>(i, z);
         }
 
         rPosition[columnIndex] = rPosition[columnIndex] + 1;
@@ -260,33 +256,32 @@ void NREstimate::startAnalyse()
 
     //-- This part of the code would involve the sd matrix and make the mean and the std of the data -------------------
 
-    CvScalar std;
-    CvScalar mean;
+    cv::Scalar std;
+    cv::Scalar mean;
     int      totalcount = 0; // Number of non-empty clusters
-    CvMat* meanStore    = cvCreateMat(d->clusterCount, points->cols, CV_32FC1);
-    CvMat* stdStore     = cvCreateMat(d->clusterCount, points->cols, CV_32FC1);
-    float* meanStorePtr = reinterpret_cast<float*>(meanStore->data.ptr);
-    float* stdStorePtr  = reinterpret_cast<float*>(stdStore->data.ptr);
+    cv::Mat meanStore    = cv::Mat(d->clusterCount, points.cols, CV_32FC1);
+    cv::Mat stdStore     = cv::Mat(d->clusterCount, points.cols, CV_32FC1);
+    float* meanStorePtr = reinterpret_cast<float*>(meanStore.data);
+    float* stdStorePtr  = reinterpret_cast<float*>(stdStore.data);
 
-    for (int i = 0 ; runningFlag() && (i < sd->cols) ; ++i)
+    for (int i = 0 ; runningFlag() && (i < sd.cols) ; ++i)
     {
         // cppcheck-suppress knownConditionTrueFalse
-        if (runningFlag() && (rowPosition[(i/points->cols)] >= 1))
+        if (runningFlag() && (rowPosition[(i/points.cols)] >= 1))
         {
-            CvMat* workingArr = cvCreateMat(rowPosition[(i / points->cols)], 1, CV_32FC1);
-            ptr               = reinterpret_cast<float*>(workingArr->data.ptr);
+            cv::Mat workingArr = cv::Mat(rowPosition[(i / points.cols)], 1, CV_32FC1);
+            ptr               = reinterpret_cast<float*>(workingArr.data);
 
             // cppcheck-suppress knownConditionTrueFalse
-            for (int j = 0 ; runningFlag() && (j < rowPosition[(i / (points->cols))]) ; ++j)
+            for (int j = 0 ; runningFlag() && (j < rowPosition[(i / (points.cols))]) ; ++j)
             {
-                *ptr++ = cvGet2D(sd, j, i).val[0];
+                *ptr++ = sd.at<float>(j, i);
             }
 
-            cvAvgSdv(workingArr, &mean, &std);
+            cv::meanStdDev(workingArr, mean, std);
             *meanStorePtr++ = (float)mean.val[0];
             *stdStorePtr++  = (float)std.val[0];
             totalcount++;
-            cvReleaseMat(&workingArr);
         }
     }
 
@@ -295,8 +290,8 @@ void NREstimate::startAnalyse()
 
     // -----------------------------------------------------------------------------------------------------------------
 
-    meanStorePtr = reinterpret_cast<float*>(meanStore->data.ptr);
-    stdStorePtr  = reinterpret_cast<float*>(stdStore->data.ptr);
+    meanStorePtr = reinterpret_cast<float*>(meanStore.data);
+    stdStorePtr  = reinterpret_cast<float*>(stdStore.data);
 
     if (runningFlag() && !d->path.isEmpty())
     {
@@ -367,10 +362,10 @@ void NREstimate::startAnalyse()
     float   weightedStd  = 0.0f;
     float   datasd[3]    = {0.0f, 0.0f, 0.0f};
 
-    for (int j = 0 ; runningFlag() && (j < points->cols) ; ++j)
+    for (int j = 0 ; runningFlag() && (j < points.cols) ; ++j)
     {
-        meanStorePtr = reinterpret_cast<float*>(meanStore->data.ptr);
-        stdStorePtr  = reinterpret_cast<float*>(stdStore->data.ptr);
+        meanStorePtr = reinterpret_cast<float*>(meanStore.data);
+        stdStorePtr  = reinterpret_cast<float*>(stdStore.data);
 
         for (int moveToChannel = 0 ; moveToChannel <= j ; ++moveToChannel)
         {
@@ -384,8 +379,8 @@ void NREstimate::startAnalyse()
             {
                 weightedMean += (*meanStorePtr) * rowPosition[i];
                 weightedStd  += (*stdStorePtr)  * rowPosition[i];
-                meanStorePtr += points->cols;
-                stdStorePtr  += points->cols;
+                meanStorePtr += points.cols;
+                stdStorePtr  += points.cols;
             }
         }
 
@@ -431,7 +426,7 @@ void NREstimate::startAnalyse()
 
         if (m_orgImage.sixteenBit())
         {
-            for (int i = 0 ; i < points->cols ; ++i)
+            for (int i = 0 ; i < points.cols ; ++i)
             {
                 if (i < 3)
                 {
@@ -513,12 +508,6 @@ void NREstimate::startAnalyse()
     postProgress(90);
 
     //-- releasing matrices and closing files ----------------------------------------------------------------------
-
-    cvReleaseMat(&sd);
-    cvReleaseMat(&stdStore);
-    cvReleaseMat(&meanStore);
-    cvReleaseMat(&points);
-    cvReleaseMat(&clusters);
 
     for (uint i = 0 ; i < 3 ; ++i)
     {
