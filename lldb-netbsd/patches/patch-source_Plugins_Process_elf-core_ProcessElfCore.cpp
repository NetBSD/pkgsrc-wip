$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2017-04-07 18:43:45.161040278 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -220,7 +220,7 @@ Error ProcessElfCore::DoLoadCore() {
   target_arch.MergeFrom(core_arch);
   GetTarget().SetArchitecture(target_arch);
  
-  SetUnixSignals(UnixSignals::Create(GetArchitecture()));
+  SetUnixSignals(UnixSignals::Create(target_arch));
 
   // Ensure we found at least one thread that was stopped on a signal.
   bool siginfo_signal_found = false;
@@ -724,17 +724,7 @@ uint32_t ProcessElfCore::GetNumThreadCon
 }
 
 ArchSpec ProcessElfCore::GetArchitecture() {
-  ObjectFileELF *core_file =
-      (ObjectFileELF *)(m_core_module_sp->GetObjectFile());
-  ArchSpec arch;
-  core_file->GetArchitecture(arch);
-
-  ArchSpec target_arch = GetTarget().GetArchitecture();
-  
-  if (target_arch.IsMIPS())
-    return target_arch;
-
-  return arch;
+  return GetTarget().GetArchitecture();
 }
 
 const lldb::DataBufferSP ProcessElfCore::GetAuxvData() {
