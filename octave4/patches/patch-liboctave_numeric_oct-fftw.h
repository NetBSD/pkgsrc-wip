$NetBSD$

--- liboctave/numeric/oct-fftw.h.orig	2015-05-23 14:21:53.000000000 +0000
+++ liboctave/numeric/oct-fftw.h
@@ -99,7 +99,7 @@ public:
     return instance_ok () ? instance->do_method (_meth) : dummy;
   }
 
-#if defined (HAVE_FFTW3F_THREADS)
+#if defined (HAVE_FFTW3_THREADS)
   static void threads (int _nthreads)
   {
     if (instance_ok () && _nthreads != threads ())
