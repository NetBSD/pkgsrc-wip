$NetBSD$

From FreeBSD ports graphics/mesa-dri 18.3.2:

amd: Make vgpr-spilling depend on llvm version 

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230789#c14

--- src/amd/common/ac_llvm_util.c.orig	2019-04-05 10:53:23.000000000 +0000
+++ src/amd/common/ac_llvm_util.c
@@ -153,7 +153,8 @@ static LLVMTargetMachineRef ac_create_ta
 	LLVMTargetRef target = ac_get_llvm_target(triple);
 
 	snprintf(features, sizeof(features),
-		 "+DumpCode,+vgpr-spilling,-fp32-denormals,+fp64-denormals%s%s%s%s",
+		 "+DumpCode,-fp32-denormals,+fp64-denormals%s%s%s%s%s",
+		 HAVE_LLVM >= 0x0800 ? "" : ",+vgpr-spilling",
 		 tm_options & AC_TM_SISCHED ? ",+si-scheduler" : "",
 		 tm_options & AC_TM_FORCE_ENABLE_XNACK ? ",+xnack" : "",
 		 tm_options & AC_TM_FORCE_DISABLE_XNACK ? ",-xnack" : "",
