$NetBSD$

--- include/pub_tool_machine.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_machine.h
@@ -41,7 +41,7 @@
                                        //   be larger than VG_MAX_INSTR_SZB
 #  define VG_STACK_REDZONE_SZB      0  // number of addressable bytes below %RSP
 
-#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris)
+#elif defined(VGP_amd64_linux) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 #  define VG_MIN_INSTR_SZB          1
 #  define VG_MAX_INSTR_SZB         16
 #  define VG_CLREQ_SZB             19
