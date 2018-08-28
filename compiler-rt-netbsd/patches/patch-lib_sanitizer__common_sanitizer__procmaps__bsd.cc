$NetBSD$

--- lib/sanitizer_common/sanitizer_procmaps_bsd.cc.orig	2018-08-21 21:25:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_procmaps_bsd.cc
@@ -67,8 +67,8 @@ void ReadProcMaps(ProcSelfMapsBuff *proc
 #endif
   };
 
-  size_t Size = 0;
-  int Err = sysctl(Mib, ARRAY_SIZE(Mib), NULL, &Size, NULL, 0);
+  uptr Size = 0;
+  int Err = internal_sysctl(Mib, ARRAY_SIZE(Mib), NULL, &Size, NULL, 0);
   CHECK_EQ(Err, 0);
   CHECK_GT(Size, 0);
 
@@ -76,7 +76,7 @@ void ReadProcMaps(ProcSelfMapsBuff *proc
   size_t MmapedSize = Size * 4 / 3;
   void *VmMap = MmapOrDie(MmapedSize, "ReadProcMaps()");
   Size = MmapedSize;
-  Err = sysctl(Mib, ARRAY_SIZE(Mib), VmMap, &Size, NULL, 0);
+  Err = internal_sysctl(Mib, ARRAY_SIZE(Mib), VmMap, &Size, NULL, 0);
   CHECK_EQ(Err, 0);
   proc_maps->data = (char *)VmMap;
 #else
@@ -88,7 +88,7 @@ void ReadProcMaps(ProcSelfMapsBuff *proc
   if (Size > 0x10000)
     Size = 0x10000;
   Size = (Size / sizeof(struct kinfo_vmentry)) * sizeof(struct kinfo_vmentry);
-  Err = sysctl(Mib, ARRAY_SIZE(Mib), Mem, &Size, NULL, 0);
+  Err = internal_sysctl(Mib, ARRAY_SIZE(Mib), Mem, &Size, NULL, 0);
   CHECK_EQ(Err, 0);
   MmapedSize = Size;
   proc_maps->data = Mem;
