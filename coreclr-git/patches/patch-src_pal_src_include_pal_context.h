$NetBSD$

--- src/pal/src/include/pal/context.h.orig	2016-02-07 15:52:01.000000000 +0000
+++ src/pal/src/include/pal/context.h
@@ -68,6 +68,20 @@ typedef ucontext_t native_context_t;
 #define MCREG_R15(mc)       ((mc).__gregs[_REG_R15])
 #define MCREG_EFlags(mc)    ((mc).__gregs[_REG_RFLAGS])
 
+#define FPREG_Xmm(uc, index) *(M128A*)&(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_xmm[index])
+
+#define FPREG_St(uc, index) *(M128A*)&(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_87_ac[index])
+
+#define FPREG_ControlWord(uc) (((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_cw)
+#define FPREG_StatusWord(uc) (((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_sw)
+#define FPREG_TagWord(uc) (((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_tw)
+#define FPREG_ErrorOffset(uc) (*(DWORD*) &(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_ip))
+#define FPREG_ErrorSelector(uc) *((WORD*) &(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_ip) + 2)
+#define FPREG_DataOffset(uc) (*(DWORD*) &(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_dp))
+#define FPREG_DataSelector(uc) *((WORD*) &(((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_dp) + 2)
+#define FPREG_MxCsr(uc) (((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_mxcsr)
+#define FPREG_MxCsr_Mask(uc) (((struct fxsave*)(&(uc)->uc_mcontext.__fpregs))->fx_mxcsr_mask)
+
 #else // BIT64
 
 #define MCREG_Ebx(mc)       ((mc).__gregs[_REG_EBX])
