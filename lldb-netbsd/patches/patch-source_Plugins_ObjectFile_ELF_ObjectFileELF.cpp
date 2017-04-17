$NetBSD$

--- source/Plugins/ObjectFile/ELF/ObjectFileELF.cpp.orig	2017-04-07 18:27:43.000000000 +0000
+++ source/Plugins/ObjectFile/ELF/ObjectFileELF.cpp
@@ -51,7 +51,7 @@ namespace {
 // ELF note owner definitions
 const char *const LLDB_NT_OWNER_FREEBSD = "FreeBSD";
 const char *const LLDB_NT_OWNER_GNU = "GNU";
-const char *const LLDB_NT_OWNER_NETBSD = "NetBSD";
+const char *const LLDB_NT_OWNER_NETBSD = "NetBSD-CORE";
 const char *const LLDB_NT_OWNER_OPENBSD = "OpenBSD";
 const char *const LLDB_NT_OWNER_CSR = "csr";
 const char *const LLDB_NT_OWNER_ANDROID = "Android";
@@ -67,9 +67,6 @@ const elf_word LLDB_NT_GNU_ABI_SIZE = 16
 
 const elf_word LLDB_NT_GNU_BUILD_ID_TAG = 0x03;
 
-const elf_word LLDB_NT_NETBSD_ABI_TAG = 0x01;
-const elf_word LLDB_NT_NETBSD_ABI_SIZE = 4;
-
 // GNU ABI note OS constants
 const elf_word LLDB_NT_GNU_ABI_OS_LINUX = 0x00;
 const elf_word LLDB_NT_GNU_ABI_OS_HURD = 0x01;
@@ -1371,24 +1368,10 @@ ObjectFileELF::RefineModuleDetailsFromNo
         arch_spec.GetTriple().setOS(llvm::Triple::OSType::Linux);
     }
     // Process NetBSD ELF notes.
-    else if ((note.n_name == LLDB_NT_OWNER_NETBSD) &&
-             (note.n_type == LLDB_NT_NETBSD_ABI_TAG) &&
-             (note.n_descsz == LLDB_NT_NETBSD_ABI_SIZE)) {
-      // Pull out the min version info.
-      uint32_t version_info;
-      if (data.GetU32(&offset, &version_info, 1) == nullptr) {
-        error.SetErrorString("failed to read NetBSD ABI note payload");
-        return error;
-      }
-
+    else if (note.n_name == LLDB_NT_OWNER_NETBSD) {
       // Set the elf OS version to NetBSD.  Also clear the vendor.
       arch_spec.GetTriple().setOS(llvm::Triple::OSType::NetBSD);
       arch_spec.GetTriple().setVendor(llvm::Triple::VendorType::UnknownVendor);
-
-      if (log)
-        log->Printf(
-            "ObjectFileELF::%s detected NetBSD, min version constant %" PRIu32,
-            __FUNCTION__, version_info);
     }
     // Process OpenBSD ELF notes.
     else if (note.n_name == LLDB_NT_OWNER_OPENBSD) {
