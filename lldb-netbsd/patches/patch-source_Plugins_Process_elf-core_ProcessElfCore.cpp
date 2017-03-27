$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2017-03-27 00:48:38.266378385 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -449,6 +449,16 @@ enum {
 };
 }
 
+namespace NETBSD {
+
+enum {
+  NT_PROCINFO = 1,
+  NT_AUXV,
+  NT_AMD64_REGS = 33,
+  NT_AMD64_FPREGS = 35
+};
+}
+
 // Parse a FreeBSD NT_PRSTATUS note - see FreeBSD sys/procfs.h for details.
 static void ParseFreeBSDPrStatus(ThreadData &thread_data, DataExtractor &data,
                                  ArchSpec &arch) {
@@ -485,6 +495,18 @@ static void ParseFreeBSDThrMisc(ThreadDa
   thread_data.name = data.GetCStr(&offset, 20);
 }
 
+static void ParseNetBSDProcInfo(ThreadData &thread_data, DataExtractor &data)
+{
+  lldb::offset_t offset = 0;
+  
+  int version = data.GetU32(&offset);
+  if (version != 1)
+	  return;
+
+  offset += 4;
+  thread_data.signo = data.GetU32(&offset);
+}
+
 static void ParseOpenBSDProcInfo(ThreadData &thread_data, DataExtractor &data)
 {
   lldb::offset_t offset = 0;
@@ -585,6 +607,19 @@ Error ProcessElfCore::ParseThreadContext
       default:
         break;
       }
+    } else if (note.n_name.substr(0, 11) == "NetBSD-CORE") {
+      // NetBSD per-thread information is stored in notes named
+      // "NetBSD-CORE@nnn" so match on the initial part of the string.
+      m_os = llvm::Triple::NetBSD;
+      if (note.n_type == NETBSD::NT_PROCINFO) {
+	 ParseNetBSDProcInfo(*thread_data, note_data);
+      } else if (note.n_type == NETBSD::NT_AUXV) {
+         m_auxv = DataExtractor(note_data);
+      } else if (arch.GetMachine() == llvm::Triple::x86_64 && note.n_type == NETBSD::NT_AMD64_REGS) {
+	thread_data->gpregset = note_data;
+      } else if (arch.GetMachine() == llvm::Triple::x86_64 && note.n_type == NETBSD::NT_AMD64_FPREGS) {
+	thread_data->fpregset = note_data;
+      }
     } else if (note.n_name.substr(0, 7) == "OpenBSD") {
       // OpenBSD per-thread information is stored in notes named
       // "OpenBSD@nnn" so match on the initial part of the string.
