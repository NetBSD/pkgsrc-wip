$NetBSD$

--- source/Plugins/DynamicLoader/POSIX-DYLD/DYLDRendezvous.cpp.orig	2017-02-04 18:35:34.000000000 +0000
+++ source/Plugins/DynamicLoader/POSIX-DYLD/DYLDRendezvous.cpp
@@ -385,6 +385,7 @@ bool DYLDRendezvous::SOEntryIsMainExecut
   auto triple = m_process->GetTarget().GetArchitecture().GetTriple();
   switch (triple.getOS()) {
   case llvm::Triple::FreeBSD:
+  case llvm::Triple::NetBSD:
     return entry.file_spec == m_exe_file_spec;
   case llvm::Triple::Linux:
     if (triple.isAndroid())
