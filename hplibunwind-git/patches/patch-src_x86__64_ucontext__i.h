$NetBSD$

--- src/x86_64/ucontext_i.h.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/x86_64/ucontext_i.h
@@ -1,5 +1,6 @@
 /* Copyright (C) 2004 Hewlett-Packard Co.
      Contributed by David Mosberger-Tang <davidm@hpl.hp.com>.
+     Copyright (C) 2018 Kamil Rytarowski <n54@gmx.com>
 
 This file is part of libunwind.
 
@@ -78,5 +79,40 @@ WITH THE SOFTWARE OR THE USE OR OTHER DE
 #define UC_MCONTEXT_FPOWNED_FPU 0x20001
 #define UC_MCONTEXT_FPFMT_XMM   0x10002
 #define UC_MCONTEXT_MC_LEN_VAL  0x320
+#elif defined __NetBSD__
+#define UC_SIGMASK               0x10
+#define UC_MCONTEXT_GREGS_RDI    0x38
+#define UC_MCONTEXT_GREGS_RSI    0x40
+#define UC_MCONTEXT_GREGS_RDX    0x48
+#define UC_MCONTEXT_GREGS_R10    0x68
+#define UC_MCONTEXT_GREGS_R8     0x58
+#define UC_MCONTEXT_GREGS_R9     0x60
+#define UC_MCONTEXT_GREGS_RCX    0x50
+#define UC_MCONTEXT_GREGS_R11    0x70
+#define UC_MCONTEXT_GREGS_R12    0x78
+#define UC_MCONTEXT_GREGS_R13    0x80
+#define UC_MCONTEXT_GREGS_R14    0x88
+#define UC_MCONTEXT_GREGS_R15    0x90
+#define UC_MCONTEXT_GREGS_RBP    0x98
+#define UC_MCONTEXT_GREGS_RBX    0xa0
+#define UC_MCONTEXT_GREGS_RAX    0xa8
+#define UC_MCONTEXT_GREGS_GS     0xb0 /* zeroed */
+#define UC_MCONTEXT_GREGS_FS     0xb8 /* zeroed */
+#define UC_MCONTEXT_GREGS_ES     0xc0
+#define UC_MCONTEXT_GREGS_DS     0xc8
+#define UC_MCONTEXT_GREGS_TRAPNO 0xd0 /* not used */
+#define UC_MCONTEXT_GREGS_ERR    0xd8 /* not used */
+#define UC_MCONTEXT_GREGS_RIP    0xe0
+#define UC_MCONTEXT_GREGS_CS     0xe8
+#define UC_MCONTEXT_GREGS_RFLAGS 0xf0
+#define UC_MCONTEXT_GREGS_RSP    0xf8
+#define UC_MCONTEXT_GREGS_SS     0x100
+#define UC_MCONTEXT_FPREGS       0x110 /* FXSAVE layout */
+#define UC_MCONTEXT_MC_TLSBASE   0x108
+#define UC_FLAGS_SIGMASK         0x1
+#define UC_FLAGS_STACK           0x2
+#define UC_FLAGS_CPU             0x4
+#define UC_FLAGS_FPU             0x8
+#define UC_FLAGS_TLSBASE         0x80000
 
 #endif
