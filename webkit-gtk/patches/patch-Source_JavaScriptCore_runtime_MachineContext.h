$NetBSD$

Add support for NetBSD

XXX:
XXX: Only CPU(X86_64) was tested and all other CPU should be reviewed and maybe
XXX: adjusted (especially ARM, ARM64 and MIPS!).
XXX:
XXX: Probably using `OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)'
XXX: can be a good way to adapt it and then check
XXX: src/sys/arch/*/include/mcontext.h for the corresponding registers.
XXX:

--- Source/JavaScriptCore/runtime/MachineContext.h.orig	2018-08-21 16:06:10.000000000 +0000
+++ Source/JavaScriptCore/runtime/MachineContext.h
@@ -188,6 +188,18 @@ static inline void*& stackPointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_UESP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSP]);
+#elif CPU(ARM) || CPU(ARM64) || CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 #if CPU(X86)
@@ -335,6 +347,20 @@ static inline void*& framePointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EBP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RBP]);
+#elif CPU(ARM) || CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_S8]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -482,6 +508,20 @@ static inline void*& instructionPointerI
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EIP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RIP]);
+#elif CPU(ARM) || CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EPC]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -639,6 +679,20 @@ inline void*& argumentPointer<1>(mcontex
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EDX]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSI]);
+#elif CPU(ARM) || CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R1]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_A1]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -756,6 +810,20 @@ inline void*& llintInstructionPointer(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_ESI]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM) || CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_T4]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
