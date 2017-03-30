$NetBSD$

--- source/Plugins/DynamicLoader/POSIX-DYLD/DYLDRendezvous.cpp.orig	2017-03-23 15:49:52.000000000 +0000
+++ source/Plugins/DynamicLoader/POSIX-DYLD/DYLDRendezvous.cpp
@@ -379,12 +379,13 @@ bool DYLDRendezvous::RemoveSOEntries() {
 }
 
 bool DYLDRendezvous::SOEntryIsMainExecutable(const SOEntry &entry) {
-  // On Linux the executable is indicated by an empty path in the entry. On
-  // FreeBSD and on Android it is the full path to the executable.
+  // On some systes the executable is indicated by an empty path in the entry.
+  // On others it is the full path to the executable.
 
   auto triple = m_process->GetTarget().GetArchitecture().GetTriple();
   switch (triple.getOS()) {
   case llvm::Triple::FreeBSD:
+  case llvm::Triple::NetBSD:
     return entry.file_spec == m_exe_file_spec;
   case llvm::Triple::Linux:
     if (triple.isAndroid())
