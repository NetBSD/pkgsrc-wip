$NetBSD: patch-src_arm_sysv.S,v 1.2 2014/06/11 12:14:17 thomasklausner Exp $

--- src/arm/sysv.S.orig	2014-04-25 17:45:13.000000000 +0000
+++ src/arm/sysv.S
@@ -25,6 +25,8 @@
    DEALINGS IN THE SOFTWARE.
    ----------------------------------------------------------------------- */
 
+.syntax unified
+
 #define LIBFFI_ASM	
 #include <fficonfig.h>
 #include <ffi.h>
@@ -103,7 +105,7 @@
 #endif
 
 /* Conditionally compile unwinder directives.  */
-#ifdef __ARM_EABI__
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
 #define UNWIND
 #else
 #define UNWIND @
@@ -122,6 +124,7 @@
 	nop; \
 	.arm; \
 	UNWIND .fnstart; \
+	.cfi_startproc; \
 _L__##name:
 #else
 #define ARM_FUNC_START(name) \
@@ -129,7 +132,8 @@ _L__##name:
 	.align 2; \
 	.arm; \
 	ENTRY(name); \
-	UNWIND .fnstart
+	UNWIND .fnstart; \
+	.cfi_startproc
 #endif
 
 .macro	RETLDM	regs=, cond=, dirn=ia
@@ -238,6 +242,7 @@ LSYM(Lepilogue):
 
 .ffi_call_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_call_SYSV),.ffi_call_SYSV_end-CNAME(ffi_call_SYSV)
 #endif
@@ -313,6 +318,7 @@ ARM_FUNC_START(ffi_closure_SYSV)
 
 .ffi_closure_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_closure_SYSV),.ffi_closure_SYSV_end-CNAME(ffi_closure_SYSV)
 #endif
@@ -396,7 +402,7 @@ LSYM(Lbase_args):
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_SINT64
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_FLOAT
@@ -416,6 +422,7 @@ LSYM(Lepilogue_vfp):
 
 .ffi_call_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_call_VFP),.ffi_call_VFP_end-CNAME(ffi_call_VFP)
 
 
@@ -478,6 +485,7 @@ ARM_FUNC_START(ffi_closure_VFP)
 
 .ffi_closure_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_closure_VFP),.ffi_closure_VFP_end-CNAME(ffi_closure_VFP)
 #endif
 
