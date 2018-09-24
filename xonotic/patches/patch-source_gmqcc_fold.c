$NetBSD$
--- ./source/gmqcc/fold.c.orig	2018-09-23 17:50:03.802080690 -0700
+++ ./source/gmqcc/fold.c	2018-09-23 17:51:19.845394071 -0700
@@ -527,7 +527,6 @@
             compile_error(ctx, "arithmetic overflow in `%s' component", vec);
         if (state->exceptionflags & SFLOAT_UNDERFLOW)
             compile_error(ctx, "arithmetic underflow in `%s' component", vec);
-            return;
     }
     if (state->exceptionflags & SFLOAT_DIVBYZERO)
         compile_error(ctx, "division by zero");
