$NetBSD$

From NetBSD xsrc:

Use a name for the largest representable float

Actually intended to appease vax which has a floating point format
that doesn't match the same range as IEEE754 float.

(why not exp2f?)

--- src/util/u_math.h.orig	2019-04-05 10:53:23.000000000 +0000
+++ src/util/u_math.h
@@ -117,7 +117,11 @@ util_fast_exp2(float x)
    union fi epart;
 
    if(x > 129.00000f)
+#if defined(__NetBSD__)
+      return FLT_MAX;
+#else
       return 3.402823466e+38f;
+#endif
 
    if (x < -126.99999f)
       return 0.0f;
