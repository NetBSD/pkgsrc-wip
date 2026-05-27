$NetBSD$

Tweak the data layout for NetBSD/m68k, as per
https://github.com/llvm/llvm-project/issues/199826

--- src/llvm-project/llvm/lib/TargetParser/TargetDataLayout.cpp.orig	2026-05-27 13:35:30.929852884 +0000
+++ src/llvm-project/llvm/lib/TargetParser/TargetDataLayout.cpp
@@ -130,22 +130,35 @@ static std::string computeM68kDataLayout
   // FIXME how to wire it with the used object format?
   Ret += "-m:e";
 
-  // M68k pointers are always 32 bit wide even for 16-bit CPUs.
-  // The ABI only specifies 16-bit alignment.
-  // On at least the 68020+ with a 32-bit bus, there is a performance benefit
-  // to having 32-bit alignment.
-  Ret += "-p:32:16:32";
-
-  // Bytes do not require special alignment, words are word aligned and
-  // long words are word aligned at minimum.
-  Ret += "-i8:8:8-i16:16:16-i32:16:32";
+  // Ref. https://github.com/llvm/llvm-project/issues/199826,
+  // the 16-bit alignment of pointer and i32 is perhaps a linuxism...
+  // For now treat NetBSD specially.
+
+  if (! TT.IsOSNetBSD()) {
+    // M68k pointers are always 32 bit wide even for 16-bit CPUs.
+    // The ABI only specifies 16-bit alignment.
+    // On at least the 68020+ with a 32-bit bus, there is a performance benefit
+    // to having 32-bit alignment.
+    Ret += "-p:32:16:32";
+
+    // Bytes do not require special alignment, words are word aligned and
+    // long words are word aligned at minimum.
+    Ret += "-i8:8:8-i16:16:16-i32:16:32";
 
-  // FIXME no floats at the moment
+    // The registers can hold 8, 16, 32 bits
+    Ret += "-n8:16:32";
 
-  // The registers can hold 8, 16, 32 bits
-  Ret += "-n8:16:32";
+    Ret += "-a:0:16-S16";
+  } else { // NetBSD has 32-bit aligned i32 and pointers:
+    Ret += "-p:32:32:32";
+    Ret += "-i8:8:8-i16:16:16-i32:32:32";
+    // The registers can hold 8, 16, 32 bits
+    Ret += "-n8:16:32";
+    // object and stack alignment is also different:
+    Ret += "-a:0:32-S32";
+  }
 
-  Ret += "-a:0:16-S16";
+  // FIXME no floats at the moment
 
   return Ret;
 }
