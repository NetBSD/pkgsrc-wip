$NetBSD: patch-src_mesa_tnl_t__pipeline.c,v 1.1 2015/09/11 00:03:36 tnn Exp $

i386 FPU control word defaults.

0x127f is the value of FreeBSD fpu.h __INITIAL_FPUCW_I386__

--- src/mesa/tnl/t_pipeline.c.orig	2017-02-13 11:55:50.000000000 +0000
+++ src/mesa/tnl/t_pipeline.c
@@ -132,7 +132,14 @@ static GLuint check_output_changes( stru
 /* Hardware default: All exceptions masked, extended double precision,
  * round to nearest (IEEE compliant):
  */
+#if defined(__NetBSD__)
+#define DEFAULT_X86_FPU	0x127f  /* __NetBSD_NPXCW__ */
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+/* __INITIAL_FPUCW_I386__ from FreeBSD fpu.h */
+#define DEFAULT_X86_FPU	0x127f
+#else
 #define DEFAULT_X86_FPU		0x037f
+#endif
 /* All exceptions masked, single precision, round to nearest:
  */
 #define FAST_X86_FPU		0x003f
