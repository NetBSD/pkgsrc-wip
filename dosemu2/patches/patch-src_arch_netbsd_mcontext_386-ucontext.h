$NetBSD$

--- src/arch/netbsd/mcontext/386-ucontext.h.orig	2017-11-02 06:34:51.947631491 +0000
+++ src/arch/netbsd/mcontext/386-ucontext.h
@@ -0,0 +1,60 @@
+/*-
+ * Copyright (c) 1999 Marcel Moolenaar
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer
+ *    in this position and unchanged.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. The name of the author may not be used to endorse or promote products
+ *    derived from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
+ * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
+ * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
+ * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
+ * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+ * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+ * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
+ * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ *
+ * $FreeBSD: src/sys/i386/include/ucontext.h,v 1.4 1999/10/11 20:33:09 luoqi Exp $
+ */
+
+struct m_mcontext {
+	/*
+	 * The first 20 fields must match the definition of
+	 * sigcontext. So that we can support sigcontext
+	 * and ucontext_t at the same time.
+	 */
+	int	mc_onstack;		/* XXX - sigcontext compat. */
+	int	mc_gs;
+	int	mc_fs;
+	int	mc_es;
+	int	mc_ds;
+	int	mc_edi;
+	int	mc_esi;
+	int	mc_ebp;
+	int	mc_isp;
+	int	mc_ebx;
+	int	mc_edx;
+	int	mc_ecx;
+	int	mc_eax;
+	int	mc_trapno;
+	int	mc_err;
+	int	mc_eip;
+	int	mc_cs;
+	int	mc_eflags;
+	int	mc_esp;			/* machine state */
+	int	mc_ss;
+
+	int	mc_fpregs[28];		/* env87 + fpacc87 + u_long */
+	int	__spare__[17];
+};
