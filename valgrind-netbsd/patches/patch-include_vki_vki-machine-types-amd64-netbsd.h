$NetBSD$

--- include/vki/vki-machine-types-amd64-netbsd.h.orig	2019-03-30 06:21:05.020121263 +0000
+++ include/vki/vki-machine-types-amd64-netbsd.h
@@ -0,0 +1,222 @@
+
+/*--------------------------------------------------------------------*/
+/*--- amd64/NetBSD-specific kernel interface: posix types.         ---*/
+/*---                                vki_posixtypes-amd64-netbsd.h ---*/
+/*--------------------------------------------------------------------*/
+
+/*
+   This file is part of Valgrind, a dynamic binary instrumentation
+   framework.
+
+   Copyright (C) 2000-2005 Julian Seward 
+      jseward@acm.org
+
+   This program is free software; you can redistribute it and/or
+   modify it under the terms of the GNU General Public License as
+   published by the Free Software Foundation; either version 2 of the
+   License, or (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307, USA.
+
+   The GNU General Public License is contained in the file COPYING.
+*/
+
+#ifndef __VKI_MACHINE_TYPES_AMD64_NETBSD_H
+#define __VKI_MACHINE_TYPES_AMD64_NETBSD_H
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/int_types.h
+//----------------------------------------------------------------------
+
+typedef signed char	vki_int8_t;
+typedef unsigned char	vki_uint8_t;
+typedef short		vki_int16_t;
+typedef unsigned short	vki_uint16_t;
+typedef int		vki_int32_t;
+typedef unsigned int	vki_uint32_t;
+typedef long		vki_int64_t;
+typedef unsigned long	vki_uint64_t;
+typedef unsigned long	vki_uintptr_t;
+typedef long		vki_intptr_t;
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/types.h
+//----------------------------------------------------------------------
+
+typedef unsigned long   vki_paddr_t;
+typedef unsigned long   vki_psize_t;
+typedef unsigned long   vki_vaddr_t;
+typedef unsigned long   vki_vsize_t;
+typedef long int        vki_register_t;
+typedef int             vki_register32_t;
+
+typedef long int        vki___register_t;
+typedef unsigned char   vki___cpu_simple_lock_nv_t;
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/ansi.h
+//----------------------------------------------------------------------
+
+typedef unsigned int    vki_bsd_clock_t;
+typedef long            vki_bsd_ptrdiff_t;
+typedef unsigned long   vki_bsd_size_t;
+typedef long            vki_bsd_ssize_t;
+typedef vki_int64_t     vki_bsd_time_t;
+typedef int             vki_bsd_clockid_t;
+typedef int             vki_bsd_timer_t;
+typedef int             vki_bsd_suseconds_t;
+typedef unsigned int    vki_bsd_useconds_t;
+typedef int             vki_bsd_wchar_t;
+typedef int             vki_bsd_wint_t;
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/limits.h
+//----------------------------------------------------------------------
+
+#define VKI_CHAR_BIT        8
+
+#define VKI_UCHAR_MAX       0xff
+#define VKI_SCHAR_MAX       0x7f
+#define VKI_SCHAR_MIN       (-0x7f-1)
+
+#define VKI_USHRT_MAX       0xffff
+#define VKI_SHRT_MAX        0x7fff
+#define VKI_SHRT_MIN        (-0x7fff-1)
+
+#define VKI_UINT_MAX        0xffffffffU
+#define VKI_INT_MAX         0x7fffffff
+#define VKI_INT_MIN         (-0x7fffffff-1)
+
+#define VKI_ULONG_MAX       0xffffffffffffffffUL
+#define VKI_LONG_MAX        0x7fffffffffffffffL
+#define VKI_LONG_MIN        (-0x7fffffffffffffffL-1)
+
+#define VKI_SSIZE_MAX       VKI_LONG_MAX
+
+#define VKI_ULLONG_MAX      0xffffffffffffffffULL
+#define VKI_LLONG_MAX       0x7fffffffffffffffLL
+#define VKI_LLONG_MIN       (-0x7fffffffffffffffLL-1)
+
+#define VKI_SSIZE_MIN       VKI_LONG_MIN
+#define VKI_SIZE_T_MAX      VKI_ULONG_MAX
+
+#define VKI_UQUAD_MAX       0xffffffffffffffffULL
+#define VKI_QUAD_MAX        0x7fffffffffffffffLL
+#define VKI_QUAD_MIN        (-0x7fffffffffffffffLL-1)
+
+#define VKI_LONG_BIT        64
+#define VKI_WORD_BIT        32
+
+#define VKI_DBL_DIG         __DBL_DIG__
+#define VKI_DBL_MAX         __DBL_MAX__
+#define VKI_DBL_MIN         __DBL_MIN__
+
+#define VKI_FLT_DIG         __FLT_DIG__
+#define VKI_FLT_MAX         __FLT_MAX__
+#define VKI_FLT_MIN         __FLT_MIN__
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/frame_regs.h
+//----------------------------------------------------------------------
+
+#define VKI__FRAME_REG(greg, freg)  \
+        greg(rdi, RDI, 0)       /* tf_rdi */ \
+        greg(rsi, RSI, 1)       /* tf_rsi */ \
+        greg(rdx, RDX, 2)       /* tf_rdx */ \
+        greg(r10, R10, 6)       /* tf_r10 */ \
+        greg(r8,  R8,  4)       /* tf_r8 */ \
+        greg(r9,  R9,  5)       /* tf_r9 */ \
+        freg(arg6, @,  @)       /* tf_arg6: syscall arg from stack */ \
+        freg(arg7, @,  @)       /* tf_arg7: syscall arg from stack */ \
+        freg(arg8, @,  @)       /* tf_arg8: syscall arg from stack */ \
+        freg(arg9, @,  @)       /* tf_arg9: syscall arg from stack */ \
+        greg(rcx, RCX, 3)       /* tf_rcx */ \
+        greg(r11, R11, 7)       /* tf_r11 */ \
+        greg(r12, R12, 8)       /* tf_r12 */ \
+        greg(r13, R13, 9)       /* tf_r13 */ \
+        greg(r14, R14, 10)      /* tf_r14 */ \
+        greg(r15, R15, 11)      /* tf_r15 */ \
+        greg(rbp, RBP, 12)      /* tf_rbp */ \
+        greg(rbx, RBX, 13)      /* tf_rbx */ \
+        greg(rax, RAX, 14)      /* tf_rax */ \
+        greg(gs,  GS,  15)      /* tf_gs */ \
+        greg(fs,  FS,  16)      /* tf_fs */ \
+        greg(es,  ES,  17)      /* tf_es */ \
+        greg(ds,  DS,  18)      /* tf_ds */ \
+        greg(trapno, TRAPNO,    /* tf_trapno */ \
+            19) \
+        /* Below portion defined in hardware */ \
+        greg(err, ERR, 20)      /* tf_err: Dummy inserted if not defined */ \
+        greg(rip, RIP, 21)      /* tf_rip */ \
+        greg(cs,  CS,  22)      /* tf_cs */ \
+        greg(rflags, RFLAGS,    /* tf_rflags */ \
+            23) \
+        /* These are pushed unconditionally on the x86-64 */ \
+        greg(rsp, RSP, 24)      /* tf_rsp */ \
+        greg(ss,  SS,  25)      /* tf_ss */
+
+#define VKI__FRAME_NOREG(reg, REG, idx)
+
+#define VKI__FRAME_GREG(greg) VKI__FRAME_REG(greg, VKI__FRAME_NOREG)
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/mcontext.h
+//----------------------------------------------------------------------
+
+#define VKI_GREG_OFFSETS(reg, REG, idx) VKI__REG_##REG = idx,
+enum { VKI__FRAME_GREG(VKI_GREG_OFFSETS) VKI__NGREG = 26 };
+#undef VKI_GREG_OFFSETS
+
+typedef unsigned long   vki___greg_t;
+typedef vki___greg_t        vki___gregset_t[VKI__NGREG];
+  
+#define VKI__REG_URSP       VKI__REG_RSP
+#define VKI__REG_RFL        VKI__REG_RFLAGS
+
+typedef char vki___fpregset_t[512] __attribute__((__aligned__(8)));
+                                                                                                                                                             
+typedef struct vki_mcontext {
+        vki___gregset_t     __gregs;
+        vki___greg_t        _mc_tlsbase;
+        vki___fpregset_t    __fpregs;
+} vki_mcontext_t;
+
+#define VKI__UC_UCONTEXT_ALIGN      (~0xf)
+
+/* AMD64 ABI 128-bytes "red zone". */                                                                                                                        
+#define VKI__UC_MACHINE_SP(uc)      ((uc)->uc_mcontext.__gregs[VKI__REG_RSP] - 128)
+#define VKI__UC_MACHINE_FP(uc)      ((uc)->uc_mcontext.__gregs[VKI__REG_RBP])
+#define VKI__UC_MACHINE_PC(uc)      ((uc)->uc_mcontext.__gregs[VKI__REG_RIP])
+#define VKI__UC_MACHINE_INTRV(uc)   ((uc)->uc_mcontext.__gregs[VKI__REG_RAX])
+
+#define VKI__UC_MACHINE_SET_PC(uc, pc)      _UC_MACHINE_PC(uc) = (pc)
+
+#define VKI__UC_TLSBASE     0x00080000
+                                                                                                                                                             
+/*
+ * mcontext extensions to handle signal delivery.
+ */
+#define VKI__UC_SETSTACK    0x00010000
+#define VKI__UC_CLRSTACK    0x00020000
+
+#define VKI___UCONTEXT_SIZE 784
+
+//----------------------------------------------------------------------
+// From sys/arch/amd64/include/cdefs.h
+//----------------------------------------------------------------------
+
+#define VKI___ALIGNBYTES            (sizeof(long) - 1)
+
+#endif // __VKI_MACHINE_TYPES_AMD64_NETBSD_H
+
+/*--------------------------------------------------------------------*/
+/*--- end                                                          ---*/
+/*--------------------------------------------------------------------*/
