$NetBSD$

--- lld/ELF/Arch/AArch64.cpp.orig	2019-10-23 20:24:31.000000000 +0000
+++ lld/ELF/Arch/AArch64.cpp
@@ -67,9 +67,12 @@ AArch64::AArch64() {
   pltHeaderSize = 32;
   defaultMaxPageSize = 65536;
 
-  // Align to the 2 MiB page size (known as a superpage or huge page).
-  // FreeBSD automatically promotes 2 MiB-aligned allocations.
-  defaultImageBase = 0x200000;
+  if (config->targetTriple.isOSNetBSD())
+    defaultImageBase = 0x200100000;
+  else
+    // Align to the 2 MiB page size (known as a superpage or huge page).
+    // FreeBSD automatically promotes 2 MiB-aligned allocations.
+    defaultImageBase = 0x200000;
 
   needsThunks = true;
 }
