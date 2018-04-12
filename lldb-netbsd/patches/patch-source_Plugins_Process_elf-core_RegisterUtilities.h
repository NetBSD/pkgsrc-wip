$NetBSD$

--- source/Plugins/Process/elf-core/RegisterUtilities.h.orig	2018-02-02 18:39:12.000000000 +0000
+++ source/Plugins/Process/elf-core/RegisterUtilities.h
@@ -28,9 +28,46 @@ enum {
 }
 
 namespace NETBSD {
-enum { NT_PROCINFO = 1, NT_AUXV, NT_AMD64_REGS = 33, NT_AMD64_FPREGS = 35 };
+enum { NT_PROCINFO = 1, NT_AUXV = 2};
+
+/* Size in bytes */
+enum { NT_PROCINFO_SIZE = 160 };
+
+/* Size in bytes */
+enum {
+  NT_PROCINFO_CPI_VERSION_SIZE = 4,
+  NT_PROCINFO_CPI_CPISIZE_SIZE = 4,
+  NT_PROCINFO_CPI_SIGNO_SIZE = 4,
+  NT_PROCINFO_CPI_SIGCODE_SIZE = 4,
+  NT_PROCINFO_CPI_SIGPEND_SIZE = 16,
+  NT_PROCINFO_CPI_SIGMASK_SIZE = 16,
+  NT_PROCINFO_CPI_SIGIGNORE_SIZE = 16,
+  NT_PROCINFO_CPI_SIGCATCH_SIZE = 16,
+  NT_PROCINFO_CPI_PID_SIZE = 4,
+  NT_PROCINFO_CPI_PPID_SIZE = 4,
+  NT_PROCINFO_CPI_PGRP_SIZE = 4,
+  NT_PROCINFO_CPI_SID_SIZE = 4,
+  NT_PROCINFO_CPI_RUID_SIZE = 4,
+  NT_PROCINFO_CPI_EUID_SIZE = 4,
+  NT_PROCINFO_CPI_SVUID_SIZE = 4,
+  NT_PROCINFO_CPI_RGID_SIZE = 4,
+  NT_PROCINFO_CPI_EGID_SIZE = 4,
+  NT_PROCINFO_CPI_SVGID_SIZE = 4,
+  NT_PROCINFO_CPI_NLWPS_SIZE = 4,
+  NT_PROCINFO_CPI_NAME_SIZE = 32,
+  NT_PROCINFO_CPI_SIGLWP_SIZE = 4,
+};
+
+namespace AMD64 {
+enum { NT_REGS = 33, NT_FPREGS = 35 };
+}
+
+namespace AARCH64 {
+enum { NT_REGS = 32, NT_FPREGS = 34 };
 }
 
+} // namespace NETBSD
+
 namespace OPENBSD {
 enum {
   NT_PROCINFO = 10,
@@ -92,7 +129,8 @@ constexpr RegsetDesc FPR_Desc[] = {
     // The result from FXSAVE is in NT_PRXFPREG for i386 core files
     {llvm::Triple::Linux, llvm::Triple::x86, LINUX::NT_PRXFPREG},
     {llvm::Triple::Linux, llvm::Triple::UnknownArch, LINUX::NT_FPREGSET},
-    {llvm::Triple::NetBSD, llvm::Triple::x86_64, NETBSD::NT_AMD64_FPREGS},
+    {llvm::Triple::NetBSD, llvm::Triple::aarch64, NETBSD::AARCH64::NT_FPREGS},
+    {llvm::Triple::NetBSD, llvm::Triple::x86_64, NETBSD::AMD64::NT_FPREGS},
     {llvm::Triple::OpenBSD, llvm::Triple::UnknownArch, OPENBSD::NT_FPREGS},
 };
 
