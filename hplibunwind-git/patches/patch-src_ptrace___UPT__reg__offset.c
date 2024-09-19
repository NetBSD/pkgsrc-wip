$NetBSD$

--- src/ptrace/_UPT_reg_offset.c.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/ptrace/_UPT_reg_offset.c
@@ -311,6 +311,30 @@ const int _UPT_reg_offset[UNW_REG_LAST +
 //  UNW_R_OFF(EFLAGS, rflags)
 //  UNW_R_OFF(SS, ss)
 #undef UNW_R_OFF
+#elif defined __NetBSD__
+#define UNW_R_OFF(R, r) \
+    [UNW_X86_64_##R]    = _REG_##R * 8,
+    UNW_R_OFF(RAX, rax)
+    UNW_R_OFF(RDX, rdx)
+    UNW_R_OFF(RCX, rcx)
+    UNW_R_OFF(RBX, rbx)
+    UNW_R_OFF(RSI, rsi)
+    UNW_R_OFF(RDI, rdi)
+    UNW_R_OFF(RBP, rbp)
+    UNW_R_OFF(RSP, rsp)
+    UNW_R_OFF(R8, r8)
+    UNW_R_OFF(R9, r9)
+    UNW_R_OFF(R10, r10)
+    UNW_R_OFF(R11, r11)
+    UNW_R_OFF(R12, r12)
+    UNW_R_OFF(R13, r13)
+    UNW_R_OFF(R14, r14)
+    UNW_R_OFF(R15, r15)
+    UNW_R_OFF(RIP, rip)
+//  UNW_R_OFF(CS, cs)
+//  UNW_R_OFF(EFLAGS, rflags)
+//  UNW_R_OFF(SS, ss)
+#undef UNW_R_OFF
 #elif defined __linux__
     [UNW_X86_64_RAX]    = 0x50,
     [UNW_X86_64_RDX]    = 0x60,
