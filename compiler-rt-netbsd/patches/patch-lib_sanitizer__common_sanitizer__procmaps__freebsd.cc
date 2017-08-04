$NetBSD$

--- lib/sanitizer_common/sanitizer_procmaps_freebsd.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_procmaps_freebsd.cc
@@ -11,14 +11,18 @@
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_platform.h"
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
 #include "sanitizer_common.h"
+#if SANITIZER_FREEBSD
 #include "sanitizer_freebsd.h"
+#endif
 #include "sanitizer_procmaps.h"
 
 #include <unistd.h>
 #include <sys/sysctl.h>
+#if SANITIZER_FREEBSD
 #include <sys/user.h>
+#endif
 
 // Fix 'kinfo_vmentry' definition on FreeBSD prior v9.2 in 32-bit mode.
 #if SANITIZER_FREEBSD && (SANITIZER_WORDSIZE == 32)
@@ -31,16 +35,24 @@
 namespace __sanitizer {
 
 void ReadProcMaps(ProcSelfMapsBuff *proc_maps) {
-  const int Mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid() };
+
+  const int Mib[] = {
+#if SANITIZER_FREEBSD
+  CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()
+#else
+  CTL_VM, VM_PROC, VM_PROC_MAP, getpid(), sizeof(struct kinfo_vmentry)
+#endif
+  };
+
   size_t Size = 0;
-  int Err = sysctl(Mib, 4, NULL, &Size, NULL, 0);
+  int Err = sysctl(Mib, ARRAY_SIZE(Mib), NULL, &Size, NULL, 0);
   CHECK_EQ(Err, 0);
   CHECK_GT(Size, 0);
 
   size_t MmapedSize = Size * 4 / 3;
   void *VmMap = MmapOrDie(MmapedSize, "ReadProcMaps()");
   Size = MmapedSize;
-  Err = sysctl(Mib, 4, VmMap, &Size, NULL, 0);
+  Err = sysctl(Mib, ARRAY_SIZE(Mib), VmMap, &Size, NULL, 0);
   CHECK_EQ(Err, 0);
 
   proc_maps->data = (char*)VmMap;
@@ -71,7 +83,11 @@ bool MemoryMappingLayout::Next(MemoryMap
                       VmEntry->kve_path);
   }
 
+#if SANITIZER_FREEBSD
   current_ += VmEntry->kve_structsize;
+#else
+  current_ += sizeof(*VmEntry);
+#endif
 
   return true;
 }
