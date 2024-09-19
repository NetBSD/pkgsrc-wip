$NetBSD$

--- src/x86_64/getcontext.S.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/x86_64/getcontext.S
@@ -2,6 +2,7 @@
    Copyright (C) 2008 Google, Inc
 	Contributed by Paul Pluzhnikov <ppluzhnikov@google.com>
    Copyright (C) 2010 Konstantin Belousov <kib@freebsd.org>
+   Copyright (C) 2018 Kamil Rytarowski <n54@gmx.com>
 
 This file is part of libunwind.
 
@@ -86,6 +87,8 @@ _Ux86_64_getcontext:
 	movw %gs, UC_MCONTEXT_GS(%rdi)
 #endif
 	movq $UC_MCONTEXT_MC_LEN_VAL, UC_MCONTEXT_MC_LEN(%rdi)
+#elif defined __NetBSD__
+	fxsave UC_MCONTEXT_FPREGS(%rdi)
 #else
 #error Port me
 #endif
@@ -130,5 +133,7 @@ _Ux86_64_getcontext_trace:
 	.cfi_endproc
 	.size _Ux86_64_getcontext_trace, . - _Ux86_64_getcontext_trace
 
+#ifndef __NetBSD__
       /* We do not need executable stack.  */
       .section        .note.GNU-stack,"",@progbits
+#endif
