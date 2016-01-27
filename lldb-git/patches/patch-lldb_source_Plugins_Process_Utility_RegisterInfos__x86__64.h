$NetBSD$

--- lldb/source/Plugins/Process/Utility/RegisterInfos_x86_64.h.orig	2015-12-06 02:57:30.000000000 +0000
+++ lldb/source/Plugins/Process/Utility/RegisterInfos_x86_64.h
@@ -48,7 +48,9 @@
 // Number of bytes needed to represent a YMM register.
 #define YMM_SIZE sizeof(YMMReg)
 
+#ifndef NO_DEBUGREGS
 #define DR_SIZE sizeof(((DBG*)NULL)->dr[0])
+#endif
 
 // RegisterKind: EHFrame, DWARF, Generic, Process Plugin, LLDB
 
@@ -85,10 +87,12 @@
       { dwarf_##reg##i##h_x86_64, dwarf_##reg##i##h_x86_64, LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM, lldb_##reg##i##_x86_64 }, \
       NULL, NULL }
 
+#ifndef NO_DEBUGREGS
 #define DEFINE_DR(reg, i)                                               \
     { #reg#i, NULL, DR_SIZE, DR_OFFSET(i), eEncodingUint, eFormatHex,   \
       { LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM,  \
       LLDB_INVALID_REGNUM, LLDB_INVALID_REGNUM }, NULL, NULL }
+#endif
 
 #define DEFINE_GPR_PSEUDO_32(reg32, reg64)          \
     { #reg32, NULL, 4, GPR_OFFSET(reg64), eEncodingUint,   \
@@ -251,6 +255,7 @@ g_register_infos_x86_64[] =
     DEFINE_YMM(ymm, 14),
     DEFINE_YMM(ymm, 15),
 
+#ifndef NO_DEBUGREGS
     // Debug registers for lldb internal use
     DEFINE_DR(dr, 0),
     DEFINE_DR(dr, 1),
@@ -259,7 +264,8 @@ g_register_infos_x86_64[] =
     DEFINE_DR(dr, 4),
     DEFINE_DR(dr, 5),
     DEFINE_DR(dr, 6),
-    DEFINE_DR(dr, 7)
+    DEFINE_DR(dr, 7),
+#endif
 };
 
 static_assert((sizeof(g_register_infos_x86_64) / sizeof(g_register_infos_x86_64[0])) == k_num_registers_x86_64,
@@ -314,10 +320,12 @@ do {                                    
     g_register_infos[lldb_##reg##i##_i386].byte_offset = YMM_OFFSET(i);         \
 } while(false);
 
+#ifndef NO_DEBUGREGS
 #define UPDATE_DR_INFO(reg_index)                                               \
 do {                                                                            \
     g_register_infos[lldb_dr##reg_index##_i386].byte_offset = DR_OFFSET(reg_index);  \
 } while(false);
+#endif
 
     // Update the register offsets
     UPDATE_GPR_INFO(eax,    rax);
@@ -400,6 +408,7 @@ do {                                    
     UPDATE_YMM_INFO(ymm, 6);
     UPDATE_YMM_INFO(ymm, 7);
 
+#ifndef NO_DEBUGREGS
     UPDATE_DR_INFO(0);
     UPDATE_DR_INFO(1);
     UPDATE_DR_INFO(2);
@@ -408,6 +417,7 @@ do {                                    
     UPDATE_DR_INFO(5);
     UPDATE_DR_INFO(6);
     UPDATE_DR_INFO(7);
+#endif
 
 #undef UPDATE_GPR_INFO
 #undef UPDATE_GPR_INFO_8H
