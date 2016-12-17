$NetBSD$

--- source/Plugins/Process/NetBSD/Procfs.h.orig	2016-12-17 13:23:23.785403906 +0000
+++ source/Plugins/Process/NetBSD/Procfs.h
@@ -0,0 +1,31 @@
+//===-- Procfs.h ---------------------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+// source/Plugins/Process/NetBSD/Procfs.h defines the symbols we need from
+// sys/procfs.h on Android/NetBSD for all supported architectures.
+
+#include <sys/ptrace.h>
+
+#ifdef __ANDROID__
+#if defined(__arm64__) || defined(__aarch64__)
+typedef unsigned long elf_greg_t;
+typedef elf_greg_t
+    elf_gregset_t[(sizeof(struct user_pt_regs) / sizeof(elf_greg_t))];
+typedef struct user_fpsimd_state elf_fpregset_t;
+#ifndef NT_FPREGSET
+#define NT_FPREGSET NT_PRFPREG
+#endif // NT_FPREGSET
+#elif defined(__mips__)
+#ifndef NT_FPREGSET
+#define NT_FPREGSET NT_PRFPREG
+#endif // NT_FPREGSET
+#endif
+#else // __ANDROID__
+#include <sys/procfs.h>
+#endif // __ANDROID__
