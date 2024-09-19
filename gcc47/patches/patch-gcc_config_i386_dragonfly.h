$NetBSD: patch-gcc_config_i386_dragonfly.h,v 1.2 2012/07/12 13:47:23 marino Exp $

--- gcc/config/i386/dragonfly.h.orig	2012-07-12 12:01:10.000000000 +0000
+++ gcc/config/i386/dragonfly.h
@@ -0,0 +1,101 @@
+/* Definitions for Intel 386 running DragonFly with ELF format
+   Copyright (C) 1996, 2000, 2002, 2004, 2007 Free Software Foundation, Inc.
+   Contributed by Eric Youngdale.
+   Modified for stabs-in-ELF by H.J. Lu.
+   Adapted from GNU/Linux version by John Polstra.
+   Continued development by David O'Brien <obrien@freebsd.org>
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 3, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING3.  If not see
+<http://www.gnu.org/licenses/>.  */
+
+
+/* Override the default comment-starter of "/".  */
+#undef  ASM_COMMENT_START
+#define ASM_COMMENT_START "#"
+
+#undef  ASM_APP_ON
+#define ASM_APP_ON "#APP\n"
+
+#undef  ASM_APP_OFF
+#define ASM_APP_OFF "#NO_APP\n"
+
+#undef  DBX_REGISTER_NUMBER
+#define DBX_REGISTER_NUMBER(n) \
+  (TARGET_64BIT ? dbx64_register_map[n] : svr4_dbx_register_map[n])
+
+#undef  NO_PROFILE_COUNTERS
+#define NO_PROFILE_COUNTERS	1
+
+/* Tell final.c that we don't need a label passed to mcount.  */
+
+#undef  MCOUNT_NAME
+#define MCOUNT_NAME ".mcount"
+
+/* Make gcc agree with <machine/ansi.h>.  */
+
+#undef  SIZE_TYPE
+#define SIZE_TYPE	(TARGET_64BIT ? "long unsigned int" : "unsigned int")
+
+#undef  PTRDIFF_TYPE
+#define PTRDIFF_TYPE	(TARGET_64BIT ? "long int" : "int")
+
+#undef  WCHAR_TYPE_SIZE
+#define WCHAR_TYPE_SIZE	(TARGET_64BIT ? 32 : BITS_PER_WORD)
+
+#undef  SUBTARGET_EXTRA_SPECS	/* i386.h bogusly defines it.  */
+#define SUBTARGET_EXTRA_SPECS \
+  { "dfbsd_dynamic_linker", DFBSD_DYNAMIC_LINKER }
+
+
+/* A C statement to output to the stdio stream FILE an assembler
+   command to advance the location counter to a multiple of 1<<LOG
+   bytes if it is within MAX_SKIP bytes.
+
+   This is used to align code labels according to Intel recommendations.  */
+
+#ifdef HAVE_GAS_MAX_SKIP_P2ALIGN
+#undef  ASM_OUTPUT_MAX_SKIP_ALIGN
+#define ASM_OUTPUT_MAX_SKIP_ALIGN(FILE, LOG, MAX_SKIP)					\
+  if ((LOG) != 0) {														\
+    if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\
+    else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\
+  }
+#endif
+
+/* Don't default to pcc-struct-return, we want to retain compatibility with
+   older gcc versions AND pcc-struct-return is nonreentrant.
+   (even though the SVR4 ABI for the i386 says that records and unions are
+   returned in memory).  */
+
+#undef  DEFAULT_PCC_STRUCT_RETURN
+#define DEFAULT_PCC_STRUCT_RETURN 0
+
+/* DragonFly sets the rounding precision of the FPU to 53 bits.  Let the
+   compiler get the contents of <float.h> and std::numeric_limits correct.  */
+#undef TARGET_96_ROUND_53_LONG_DOUBLE
+#define TARGET_96_ROUND_53_LONG_DOUBLE (!TARGET_64BIT)
+
+/* Put all *tf routines in libgcc.  */
+#undef LIBGCC2_HAS_TF_MODE
+#define LIBGCC2_HAS_TF_MODE 1
+#define LIBGCC2_TF_CEXT q
+#define TF_SIZE 113
+
+/* Static stack checking is supported by means of probes.  */
+#define STACK_CHECK_STATIC_BUILTIN 1
+
+/* Support for i386 has been removed from DragonFly for several releases  */
+#define SUBTARGET32_DEFAULT_CPU "i486"
