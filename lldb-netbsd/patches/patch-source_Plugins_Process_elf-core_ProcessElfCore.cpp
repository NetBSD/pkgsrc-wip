$NetBSD$

--- source/Plugins/Process/elf-core/ProcessElfCore.cpp.orig	2018-05-04 16:30:00.745959198 +0000
+++ source/Plugins/Process/elf-core/ProcessElfCore.cpp
@@ -453,16 +453,43 @@ static void ParseFreeBSDPrStatus(ThreadD
   thread_data.gpregset = DataExtractor(data, offset, len);
 }
 
-static void ParseNetBSDProcInfo(ThreadData &thread_data,
-                                const DataExtractor &data) {
+static Status ParseNetBSDProcInfo(const DataExtractor &data, uint32_t &cpi_nlwps,
+                                  uint32_t &cpi_signo, uint32_t &cpi_siglwp) {
   lldb::offset_t offset = 0;
 
-  int version = data.GetU32(&offset);
+  uint32_t version = data.GetU32(&offset);
   if (version != 1)
-    return;
+    return Status(
+        "Error parsing NetBSD core(5) notes: Unsupported procinfo version");
 
-  offset += 4;
-  thread_data.signo = data.GetU32(&offset);
+  uint32_t cpisize = data.GetU32(&offset);
+  if (cpisize != NETBSD::NT_PROCINFO_SIZE)
+    return Status(
+        "Error parsing NetBSD core(5) notes: Unsupported procinfo size");
+
+  cpi_signo = data.GetU32(&offset); /* killing signal */
+
+  offset += NETBSD::NT_PROCINFO_CPI_SIGCODE_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SIGPEND_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SIGMASK_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SIGIGNORE_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SIGCATCH_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_PID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_PPID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_PGRP_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_RUID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_EUID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SVUID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_RGID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_EGID_SIZE;
+  offset += NETBSD::NT_PROCINFO_CPI_SVGID_SIZE;
+  cpi_nlwps = data.GetU32(&offset); /* number of LWPs */
+
+  offset += NETBSD::NT_PROCINFO_CPI_NAME_SIZE;
+  cpi_siglwp = data.GetU32(&offset); /* LWP target of killing signal */
+
+  return Status();
 }
 
 static void ParseOpenBSDProcInfo(ThreadData &thread_data,
@@ -550,35 +577,99 @@ llvm::Error ProcessElfCore::parseFreeBSD
 
 llvm::Error ProcessElfCore::parseNetBSDNotes(llvm::ArrayRef<CoreNote> notes) {
   ThreadData thread_data;
-  for (const auto &note : notes) {
-    // NetBSD per-thread information is stored in notes named "NetBSD-CORE@nnn"
-    // so match on the initial part of the string.
-    if (!llvm::StringRef(note.info.n_name).startswith("NetBSD-CORE"))
-      continue;
+  ArchSpec arch = GetArchitecture();
+  /*
+   * To be extracted from struct netbsd_elfcore_procinfo
+   * Used to sanity check of the LWPs of the process
+   */
+  uint32_t nlwps = 0;
+  uint32_t signo;  /* killing signal */
+  uint32_t siglwp; /* LWP target of killing signal */
 
-    switch (note.info.n_type) {
-    case NETBSD::NT_PROCINFO:
-      ParseNetBSDProcInfo(thread_data, note.data);
-      break;
-    case NETBSD::NT_AUXV:
-      m_auxv = note.data;
-      break;
+  for (const auto &note : notes) {
+    llvm::StringRef name = note.info.n_name;
 
-    case NETBSD::NT_AMD64_REGS:
-      if (GetArchitecture().GetMachine() == llvm::Triple::x86_64)
-        thread_data.gpregset = note.data;
-      break;
-    default:
-      thread_data.notes.push_back(note);
-      break;
+    if (name == "NetBSD-CORE") {
+      if (note.info.n_type == NETBSD::NT_PROCINFO) {
+        Status error = ParseNetBSDProcInfo(note.data, nlwps, signo, siglwp);
+        if (error.Fail()) {
+          return error.ToError(); // return Status(std::move(error));
+        }
+      } else if (note.info.n_type == NETBSD::NT_AUXV) {
+        m_auxv = note.data;
+      }
+    } else if (name.consume_front("NetBSD-CORE@")) {
+      lldb::tid_t tid;
+      if (name.getAsInteger(10, tid))
+        return Status("Error parsing NetBSD core(5) notes: Cannot convert "
+                     "LWP ID to integer").ToError();
+
+      switch (arch.GetMachine()) {
+      case llvm::Triple::x86_64: {
+        /* Assume order PT_GETREGS, PT_GETFPREGS */
+        if (note.info.n_type == NETBSD::AMD64::NT_REGS) {
+          m_thread_data.push_back(ThreadData());
+          m_thread_data.back().gpregset = note.data;
+          m_thread_data.back().tid = tid;
+        } else if (note.info.n_type == NETBSD::AMD64::NT_FPREGS) {
+          m_thread_data.back().notes.push_back(note);
+        } else {
+          return Status(
+              "Error parsing NetBSD core(5) notes: Unsupported AMD64 NOTE").ToError();
+        }
+      } break;
+      case llvm::Triple::aarch64: {
+        /* Assume order PT_GETREGS, PT_GETFPREGS */
+        if (note.info.n_type == NETBSD::AARCH64::NT_REGS) {
+          m_thread_data.push_back(ThreadData());
+          m_thread_data.back().gpregset = note.data;
+          m_thread_data.back().tid = tid;
+        } else if (note.info.n_type == NETBSD::AARCH64::NT_FPREGS) {
+          m_thread_data.back().notes.push_back(note); // We need to implement an extractor of 128bit integers
+        } else {
+          return Status(
+              "Error parsing NetBSD core(5) notes: Unsupported EVBARM NOTE").ToError();
+        }
+      } break;
+      default:
+        return Status(
+            "Error parsing NetBSD core(5) notes: Unsupported architecture").ToError();
+      }
+    } else {
+      return Status("Error parsing NetBSD core(5) notes: Unrecognized note").ToError();
+     }
+   }
+
+  if (m_thread_data.empty())
+    return Status("Error parsing NetBSD core(5) notes: No threads information "
+                 "specified in notes").ToError();
+
+  if (m_thread_data.size() != nlwps)
+    return Status("Error parsing NetBSD core(5) notes: Mismatch between the "
+                 "number of LWPs in netbsd_elfcore_procinfo and the number of "
+                 "LWPs specified by MD notes").ToError();
+
+  /* The whole process signal */
+  if (siglwp == 0) {
+    for (auto &data : m_thread_data)
+      data.signo = signo;
+  }
+  /* Signal destinated for a particular LWP */
+  else {
+    bool passed = false;
+
+    for (auto &data : m_thread_data) {
+      if (data.tid == siglwp) {
+        data.signo = signo;
+        passed = true;
+        break;
+      }
     }
-  }
-  if (thread_data.gpregset.GetByteSize() == 0) {
-    return llvm::make_error<llvm::StringError>(
-        "Could not find general purpose registers note in core file.",
-        llvm::inconvertibleErrorCode());
-  }
-  m_thread_data.push_back(thread_data);
+
+    if (!passed)
+      return Status(
+          "Error parsing NetBSD core(5) notes: Signal passed to unknown LWP").ToError();
+   }
   return llvm::Error::success();
 }
 
