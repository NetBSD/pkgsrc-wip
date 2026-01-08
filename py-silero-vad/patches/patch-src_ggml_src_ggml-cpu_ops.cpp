$NetBSD$

Fix bare isnan to std::isnan

https://github.com/rhasspy/pysilero-vad/issues/9

--- src/ggml/src/ggml-cpu/ops.cpp.orig	2026-01-08 15:48:03.312828141 +0000
+++ src/ggml/src/ggml-cpu/ops.cpp
@@ -2123,8 +2123,8 @@ static void ggml_compute_forward_gelu_f3
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2163,8 +2163,8 @@ static void ggml_compute_forward_gelu_f1
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -2303,8 +2303,8 @@ static void ggml_compute_forward_gelu_er
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2343,8 +2343,8 @@ static void ggml_compute_forward_gelu_er
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -2406,8 +2406,8 @@ static void ggml_compute_forward_gelu_qu
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2446,8 +2446,8 @@ static void ggml_compute_forward_gelu_qu
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -2509,8 +2509,8 @@ static void ggml_compute_forward_silu_f3
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*(dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2549,8 +2549,8 @@ static void ggml_compute_forward_silu_f1
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*(dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -2699,8 +2699,8 @@ static void ggml_compute_forward_silu_ba
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2743,8 +2743,8 @@ static void ggml_compute_forward_silu_ba
             const float x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_CPU_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
     #endif
     }
@@ -2826,8 +2826,8 @@ static void ggml_compute_forward_reglu_f
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -2886,8 +2886,8 @@ static void ggml_compute_forward_reglu_f
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -2969,8 +2969,8 @@ static void ggml_compute_forward_geglu_f
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -3029,8 +3029,8 @@ static void ggml_compute_forward_geglu_f
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -3112,8 +3112,8 @@ static void ggml_compute_forward_swiglu_
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -3172,8 +3172,8 @@ static void ggml_compute_forward_swiglu_
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -3263,8 +3263,8 @@ static void ggml_compute_forward_swiglu_
         for (int k = 0; k < nc; k++) {
             const float x = dst_p[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -3342,8 +3342,8 @@ static void ggml_compute_forward_geglu_e
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -3402,8 +3402,8 @@ static void ggml_compute_forward_geglu_e
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -3485,8 +3485,8 @@ static void ggml_compute_forward_geglu_q
         for (int k = 0; k < nc; k++) {
             const float x = ((float *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             GGML_UNUSED(x);
-            assert(!isnan(x));
-            assert(!isinf(x));
+            assert(!std::isnan(x));
+            assert(!std::isinf(x));
         }
 #endif
     }
@@ -3545,8 +3545,8 @@ static void ggml_compute_forward_geglu_q
             const ggml_fp16_t x = ((ggml_fp16_t *) ((char *) dst->data + i1*( dst->nb[1])))[k];
             const float v = GGML_FP16_TO_FP32(x);
             GGML_UNUSED(v);
-            assert(!isnan(v));
-            assert(!isinf(v));
+            assert(!std::isnan(v));
+            assert(!std::isinf(v));
         }
 #endif
     }
@@ -5237,7 +5237,7 @@ static void ggml_compute_forward_soft_ma
 #ifndef NDEBUG
                 for (int i = 0; i < ne00; ++i) {
                     //printf("p[%d] = %f\n", i, p[i]);
-                    assert(!isnan(wp[i]));
+                    assert(!std::isnan(wp[i]));
                 }
 #endif
 
@@ -5261,8 +5261,8 @@ static void ggml_compute_forward_soft_ma
 
 #ifndef NDEBUG
                 for (int i = 0; i < ne00; ++i) {
-                    assert(!isnan(dp[i]));
-                    assert(!isinf(dp[i]));
+                    assert(!std::isnan(dp[i]));
+                    assert(!std::isinf(dp[i]));
                 }
 #endif
             }
@@ -5335,8 +5335,8 @@ static void ggml_compute_forward_soft_ma
 #ifndef NDEBUG
         for (int i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(dy[i]));
-            assert(!isnan(y[i]));
+            assert(!std::isnan(dy[i]));
+            assert(!std::isnan(y[i]));
         }
 #endif
         // Jii = yi - yi*yi
@@ -5368,8 +5368,8 @@ static void ggml_compute_forward_soft_ma
 
 #ifndef NDEBUG
         for (int i = 0; i < nc; ++i) {
-            assert(!isnan(dx[i]));
-            assert(!isinf(dx[i]));
+            assert(!std::isnan(dx[i]));
+            assert(!std::isinf(dx[i]));
         }
 #endif
     }
@@ -10040,8 +10040,8 @@ static void ggml_compute_forward_cross_e
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(s0[i]));
-            assert(!isnan(s1[i]));
+            assert(!std::isnan(s0[i]));
+            assert(!std::isnan(s1[i]));
         }
 #endif
 
@@ -10059,8 +10059,8 @@ static void ggml_compute_forward_cross_e
 
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
-            assert(!isnan(st[i]));
-            assert(!isinf(st[i]));
+            assert(!std::isnan(st[i]));
+            assert(!std::isinf(st[i]));
         }
 #endif
     }
@@ -10132,8 +10132,8 @@ static void ggml_compute_forward_cross_e
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
             //printf("p[%d] = %f\n", i, p[i]);
-            assert(!isnan(s0[i]));
-            assert(!isnan(s1[i]));
+            assert(!std::isnan(s0[i]));
+            assert(!std::isnan(s1[i]));
         }
 #endif
 
@@ -10150,8 +10150,8 @@ static void ggml_compute_forward_cross_e
 
 #ifndef NDEBUG
         for (int64_t i = 0; i < nc; ++i) {
-            assert(!isnan(ds0[i]));
-            assert(!isinf(ds0[i]));
+            assert(!std::isnan(ds0[i]));
+            assert(!std::isinf(ds0[i]));
         }
 #endif
     }
