$NetBSD$

OpenCV 5 support.
https://invent.kde.org/graphics/digikam/-/commit/abcadfdc91601fe410c67f4abba87117e81aad3e

--- core/libs/facesengine/recognition/faceclassifier.cpp.orig	2026-06-07 15:07:03.000000000 +0000
+++ core/libs/facesengine/recognition/faceclassifier.cpp
@@ -215,7 +215,7 @@ cv::Ptr<cv::ml::SVM> FaceClassifier::createSVM(int ite
     cvClassifier->setKernel(d->svm_kernel);
     cvClassifier->setGamma(d->svm_gamma);
     cvClassifier->setC(d->svm_C);
-    cvClassifier->setTermCriteria(cvTermCriteria(
+    cvClassifier->setTermCriteria(cv::TermCriteria(
                                                  cv::TermCriteria::Type::MAX_ITER + cv::TermCriteria::Type::EPS,
                                                  iterations,
                                                  d->svm_epsilon
