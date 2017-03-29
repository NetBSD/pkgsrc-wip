$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2017-03-26 19:17:32.000000000 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -62,8 +62,8 @@ lldb::ProcessSP ProcessElfCore::CreateIn
     // to ignore possible presence of the header extension.
     const size_t header_size = sizeof(llvm::ELF::Elf64_Ehdr);
 
-    auto data_sp =
-        DataBufferLLVM::CreateSliceFromPath(crash_file->GetPath(), header_size, 0);
+    auto data_sp = DataBufferLLVM::CreateSliceFromPath(crash_file->GetPath(),
+                                                       header_size, 0);
     if (data_sp && data_sp->GetByteSize() == header_size &&
         elf::ELFHeader::MagicBytesMatch(data_sp->GetBytes())) {
       elf::ELFHeader elf_header;
@@ -223,7 +223,7 @@ Error ProcessElfCore::DoLoadCore() {
   bool siginfo_signal_found = false;
   bool prstatus_signal_found = false;
   // Check we found a signal in a SIGINFO note.
-  for (const auto &thread_data: m_thread_data) {
+  for (const auto &thread_data : m_thread_data) {
     if (thread_data.signo != 0)
       siginfo_signal_found = true;
     if (thread_data.prstatus_sig != 0)
@@ -233,7 +233,7 @@ Error ProcessElfCore::DoLoadCore() {
     // If we don't have signal from SIGINFO use the signal from each threads
     // PRSTATUS note.
     if (prstatus_signal_found) {
-      for (auto &thread_data: m_thread_data)
+      for (auto &thread_data : m_thread_data)
         thread_data.signo = thread_data.prstatus_sig;
     } else if (m_thread_data.size() > 0) {
       // If all else fails force the first thread to be SIGSTOP
@@ -449,6 +449,11 @@ enum {
 };
 }
 
+namespace NETBSD {
+
+enum { NT_PROCINFO = 1, NT_AUXV, NT_AMD64_REGS = 33, NT_AMD64_FPREGS = 35 };
+}
+
 // Parse a FreeBSD NT_PRSTATUS note - see FreeBSD sys/procfs.h for details.
 static void ParseFreeBSDPrStatus(ThreadData &thread_data, DataExtractor &data,
                                  ArchSpec &arch) {
@@ -485,13 +490,23 @@ static void ParseFreeBSDThrMisc(ThreadDa
   thread_data.name = data.GetCStr(&offset, 20);
 }
 
-static void ParseOpenBSDProcInfo(ThreadData &thread_data, DataExtractor &data)
-{
+static void ParseNetBSDProcInfo(ThreadData &thread_data, DataExtractor &data) {
+  lldb::offset_t offset = 0;
+
+  int version = data.GetU32(&offset);
+  if (version != 1)
+    return;
+
+  offset += 4;
+  thread_data.signo = data.GetU32(&offset);
+}
+
+static void ParseOpenBSDProcInfo(ThreadData &thread_data, DataExtractor &data) {
   lldb::offset_t offset = 0;
-  
+
   int version = data.GetU32(&offset);
   if (version != 1)
-	  return;
+    return;
 
   offset += 4;
   thread_data.signo = data.GetU32(&offset);
@@ -585,23 +600,38 @@ Error ProcessElfCore::ParseThreadContext
       default:
         break;
       }
+    } else if (note.n_name.substr(0, 11) == "NetBSD-CORE") {
+      // NetBSD per-thread information is stored in notes named
+      // "NetBSD-CORE@nnn" so match on the initial part of the string.
+      m_os = llvm::Triple::NetBSD;
+      if (note.n_type == NETBSD::NT_PROCINFO) {
+        ParseNetBSDProcInfo(*thread_data, note_data);
+      } else if (note.n_type == NETBSD::NT_AUXV) {
+        m_auxv = DataExtractor(note_data);
+      } else if (arch.GetMachine() == llvm::Triple::x86_64 &&
+                 note.n_type == NETBSD::NT_AMD64_REGS) {
+        thread_data->gpregset = note_data;
+      } else if (arch.GetMachine() == llvm::Triple::x86_64 &&
+                 note.n_type == NETBSD::NT_AMD64_FPREGS) {
+        thread_data->fpregset = note_data;
+      }
     } else if (note.n_name.substr(0, 7) == "OpenBSD") {
       // OpenBSD per-thread information is stored in notes named
       // "OpenBSD@nnn" so match on the initial part of the string.
       m_os = llvm::Triple::OpenBSD;
       switch (note.n_type) {
       case NT_OPENBSD_PROCINFO:
-	ParseOpenBSDProcInfo(*thread_data, note_data);
-	break;
+        ParseOpenBSDProcInfo(*thread_data, note_data);
+        break;
       case NT_OPENBSD_AUXV:
-	m_auxv = DataExtractor(note_data);
-	break;
+        m_auxv = DataExtractor(note_data);
+        break;
       case NT_OPENBSD_REGS:
-	thread_data->gpregset = note_data;
-	break;
+        thread_data->gpregset = note_data;
+        break;
       case NT_OPENBSD_FPREGS:
-	thread_data->fpregset = note_data;
-	break;
+        thread_data->fpregset = note_data;
+        break;
       }
     } else if (note.n_name == "CORE") {
       switch (note.n_type) {
