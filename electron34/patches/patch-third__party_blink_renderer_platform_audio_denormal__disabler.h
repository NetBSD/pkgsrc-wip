$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/audio/denormal_disabler.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/audio/denormal_disabler.h
@@ -52,64 +52,69 @@ namespace blink {
 #endif
 
 #if defined(HAVE_DENORMAL)
-class DenormalDisabler {
-  DISALLOW_NEW();
-
+class DenormalModifier {
  public:
-  DenormalDisabler() { DisableDenormals(); }
-
-  ~DenormalDisabler() { RestoreState(); }
-
-  // This is a nop if we can flush denormals to zero in hardware.
-  static inline float FlushDenormalFloatToZero(float f) { return f; }
-
- private:
-  unsigned saved_csr_ = 0;
+  virtual ~DenormalModifier() = default;
 
 #if defined(COMPILER_GCC) && defined(ARCH_CPU_X86_FAMILY)
-  inline void DisableDenormals() {
-    saved_csr_ = GetCSR();
-    SetCSR(saved_csr_ | 0x8040);
+ public:
+  static void DisableDenormals() {
+    unsigned old_csr = GetCsr();
+    SetCsr(old_csr | 0x8040);
   }
 
-  inline void RestoreState() { SetCSR(saved_csr_); }
+  static void EnableDenormals() {
+    unsigned old_csr = GetCsr();
+    SetCsr(old_csr & (~0x8040));
+  }
 
-  inline int GetCSR() {
+ protected:
+  static inline unsigned GetCsr() {
     int result;
     asm volatile("stmxcsr %0" : "=m"(result));
     return result;
   }
 
-  inline void SetCSR(int a) {
+  static inline void SetCsr(int a) {
     int temp = a;
     asm volatile("ldmxcsr %0" : : "m"(temp));
   }
 
 #elif BUILDFLAG(IS_WIN) && defined(COMPILER_MSVC)
-  inline void DisableDenormals() {
-    // Save the current state, and set mode to flush denormals.
-    //
-    // http://stackoverflow.com/questions/637175/possible-bug-in-controlfp-s-may-not-restore-control-word-correctly
-    _controlfp_s(&saved_csr_, 0, 0);
-    unsigned unused;
-    _controlfp_s(&unused, _DN_FLUSH, _MCW_DN);
+ public:
+  static void DisableDenormals() { SetCsr(_DN_FLUSH); }
+
+  static void EnableDenormals() { SetCsr(_DN_SAVE); }
+
+ protected:
+  static inline unsigned GetCsr() {
+    unsigned result;
+    _controlfp_s(&result, 0, 0);
+    return result;
   }
 
-  inline void RestoreState() {
+  static inline void SetCsr(unsigned a) {
+    // http://stackoverflow.com/questions/637175/possible-bug-in-controlfp-s-may-not-restore-control-word-correctly
     unsigned unused;
-    _controlfp_s(&unused, saved_csr_, _MCW_DN);
+    _controlfp_s(&unused, a, _MCW_DN);
   }
+
 #elif defined(ARCH_CPU_ARM_FAMILY)
-  inline void DisableDenormals() {
-    saved_csr_ = GetStatusWord();
+ public:
+  static void DisableDenormals() {
+    unsigned old_csr = GetCsr();
     // Bit 24 is the flush-to-zero mode control bit. Setting it to 1 flushes
     // denormals to 0.
-    SetStatusWord(saved_csr_ | (1 << 24));
+    SetCsr(old_csr | (1 << 24));
   }
 
-  inline void RestoreState() { SetStatusWord(saved_csr_); }
+  static void EnableDenormals() {
+    unsigned old_csr = GetCsr();
+    SetCsr(old_csr & (~(1 << 24)));
+  }
 
-  inline int GetStatusWord() {
+ protected:
+  static inline unsigned GetCsr() {
     int result;
 #if defined(ARCH_CPU_ARM64)
     asm volatile("mrs %x[result], FPCR" : [result] "=r"(result));
@@ -119,7 +124,7 @@ class DenormalDisabler {
     return result;
   }
 
-  inline void SetStatusWord(int a) {
+  static inline void SetCsr(int a) {
 #if defined(ARCH_CPU_ARM64)
     asm volatile("msr FPCR, %x[src]" : : [src] "r"(a));
 #else
@@ -130,13 +135,53 @@ class DenormalDisabler {
 #endif
 };
 
+class DenormalDisabler final : public DenormalModifier {
+  DISALLOW_NEW();
+
+ public:
+  DenormalDisabler() {
+    // Save the current state, and set mode to flush denormals.
+    saved_csr_ = GetCsr();
+    DisableDenormals();
+  }
+  ~DenormalDisabler() final { SetCsr(saved_csr_); }
+
+  // This is a nop if we can flush denormals to zero in hardware.
+  static inline float FlushDenormalFloatToZero(float f) { return f; }
+
+ private:
+  unsigned saved_csr_ = 0;
+};
+
+class DenormalEnabler final : public DenormalModifier {
+  DISALLOW_NEW();
+
+ public:
+  DenormalEnabler() {
+    saved_csr_ = GetCsr();
+    EnableDenormals();
+  }
+  ~DenormalEnabler() final { SetCsr(saved_csr_); }
+
+ private:
+  unsigned saved_csr_ = 0;
+};
+
 #else
 // FIXME: add implementations for other architectures and compilers
-class DenormalDisabler {
+class DenormalModifier final {
+ public:
+  virtual ~DenormalModifier() = default;
+  static void DisableDenormals() {}
+  static void EnableDenormals() {}
+};
+
+class DenormalDisabler final {
   STACK_ALLOCATED();
 
  public:
-  DenormalDisabler() {}
+  DenormalDisabler() = default;
+  ~DenormalDisabler() = default;
 
   // Assume the worst case that other architectures and compilers
   // need to flush denormals to zero manually.
@@ -145,6 +190,14 @@ class DenormalDisabler {
   }
 };
 
+class DenormalEnabler final {
+  STACK_ALLOCATED();
+
+ public:
+  DenormalEnabler() = default;
+  ~DenormalEnabler() = default;
+};
+
 #endif
 
 }  // namespace blink
