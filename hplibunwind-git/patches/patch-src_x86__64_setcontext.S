$NetBSD$

--- src/x86_64/setcontext.S.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/x86_64/setcontext.S
@@ -2,6 +2,7 @@
    Copyright (C) 2007 Google, Inc
 	Contributed by Arun Sharma <arun.sharma@google.com>
    Copyright (C) 2010 Konstantin Belousov <kib@freebsd.org>
+   Copyright (C) 2018 Kamil Rytarowski <n54@gmx.com>
 
 This file is part of libunwind.
 
@@ -50,6 +51,8 @@ _Ux86_64_setcontext:
 	jne 1f
 	fxrstor UC_MCONTEXT_FPSTATE(%rdi)
 1:
+#elif defined __NetBSD__
+	fxrstor UC_MCONTEXT_FPREGS(%rdi)
 #else
 #error Port me
 #endif
@@ -79,5 +82,7 @@ _Ux86_64_setcontext:
 
 	.size _Ux86_64_setcontext, . - _Ux86_64_setcontext
 
+#ifndef __NetBSD__
       /* We do not need executable stack.  */
       .section        .note.GNU-stack,"",@progbits
+#endif
