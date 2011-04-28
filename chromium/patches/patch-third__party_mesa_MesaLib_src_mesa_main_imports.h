$NetBSD: patch-third__party_mesa_MesaLib_src_mesa_main_imports.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/mesa/MesaLib/src/mesa/main/imports.h.orig	2011-04-13 08:01:23.000000000 +0000
+++ third_party/mesa/MesaLib/src/mesa/main/imports.h
@@ -131,6 +131,7 @@ typedef union { GLfloat f; GLint i; } fi
 #define cosf(f) ((float) cos(f))
 #define coshf(f) ((float) cosh(f))
 #define expf(f) ((float) exp(f))
+#define exp2(f) exp((f) * 0.693147180559945)
 #define exp2f(f) ((float) exp2(f))
 #define floorf(f) ((float) floor(f))
 #define logf(f) ((float) log(f))
