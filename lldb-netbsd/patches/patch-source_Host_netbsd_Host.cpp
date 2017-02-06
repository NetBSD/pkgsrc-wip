$NetBSD$

--- source/Host/netbsd/Host.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Host/netbsd/Host.cpp
@@ -1,5 +1,4 @@
-//===-- source/Host/netbsd/Host.cpp ------------------------------*- C++
-//-*-===//
+//===-- source/Host/netbsd/Host.cpp -----------------------------*- C++ -*-===//
 //
 //                     The LLVM Compiler Infrastructure
 //
@@ -260,7 +259,35 @@ bool Host::GetProcessInfo(lldb::pid_t pi
 }
 
 lldb::DataBufferSP Host::GetAuxvData(lldb_private::Process *process) {
-  return lldb::DataBufferSP();
+  /*
+   * ELF_AUX_ENTRIES is currently restricted to kernel
+   * (<sys/exec_elf.h> r. 1.155 specifies 15)
+   *
+   * ptrace(2) returns the whole AUXV including extra fiels after AT_NULL this
+   * information isn't needed.
+   */
+  size_t auxv_size = 100 * sizeof(AuxInfo);
+  DataBufferSP buf_sp;
+
+  std::unique_ptr<DataBufferHeap> buf_ap(new DataBufferHeap(auxv_size, 0));
+
+  struct ptrace_io_desc io = {
+    .piod_op = PIOD_READ_AUXV,
+    .piod_offs = 0,
+    .piod_addr = buf_ap->GetBytes(),
+    .piod_len = auxv_size
+  };
+
+  if (ptrace(PT_IO, process->GetID(), &io, 0) == -1) {
+    perror("ptrace failed on auxv");
+  } else if (io.piod_len < 1) {
+    perror("empty result for auxv");
+  } else {
+    /* Everything fine */
+    buf_sp.reset(buf_ap.release());
+  }
+
+  return buf_sp;
 }
 
 Error Host::ShellExpandArguments(ProcessLaunchInfo &launch_info) {
