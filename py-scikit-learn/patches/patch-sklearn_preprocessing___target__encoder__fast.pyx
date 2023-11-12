$NetBSD$

Fix build on NetBSD.

--- sklearn/preprocessing/_target_encoder_fast.pyx.orig	2023-10-23 10:11:35.000000000 +0000
+++ sklearn/preprocessing/_target_encoder_fast.pyx
@@ -1,4 +1,4 @@
-from libc.math cimport isnan
+from libcpp.cmath cimport isnan as isnan
 from libcpp.vector cimport vector
 
 cimport numpy as cnp
