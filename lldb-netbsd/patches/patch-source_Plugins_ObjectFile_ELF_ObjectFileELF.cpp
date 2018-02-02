$NetBSD$

--- source/Plugins/ObjectFile/ELF/ObjectFileELF.cpp.orig	2018-02-02 18:39:18.800930947 +0000
+++ source/Plugins/ObjectFile/ELF/ObjectFileELF.cpp
@@ -52,6 +52,7 @@ namespace {
 const char *const LLDB_NT_OWNER_FREEBSD = "FreeBSD";
 const char *const LLDB_NT_OWNER_GNU = "GNU";
 const char *const LLDB_NT_OWNER_NETBSD = "NetBSD";
+const char *const LLDB_NT_OWNER_NETBSDCORE = "NetBSD-CORE";
 const char *const LLDB_NT_OWNER_OPENBSD = "OpenBSD";
 const char *const LLDB_NT_OWNER_CSR = "csr";
 const char *const LLDB_NT_OWNER_ANDROID = "Android";
@@ -67,8 +68,10 @@ const elf_word LLDB_NT_GNU_ABI_SIZE = 16
 
 const elf_word LLDB_NT_GNU_BUILD_ID_TAG = 0x03;
 
-const elf_word LLDB_NT_NETBSD_ABI_TAG = 0x01;
-const elf_word LLDB_NT_NETBSD_ABI_SIZE = 4;
+const elf_word LLDB_NT_NETBSD_NT_NETBSD_IDENT_TAG = 1;
+const elf_word LLDB_NT_NETBSD_NT_NETBSD_IDENT_DESCSZ = 4;
+const elf_word LLDB_NT_NETBSD_NT_NETBSD_IDENT_NAMESZ = 7;
+const elf_word LLDB_NT_NETBSD_NT_PROCINFO = 1;
 
 // GNU ABI note OS constants
 const elf_word LLDB_NT_GNU_ABI_OS_LINUX = 0x00;
@@ -1341,25 +1344,41 @@ ObjectFileELF::RefineModuleDetailsFromNo
         // The note.n_name == LLDB_NT_OWNER_GNU is valid for Linux platform
         arch_spec.GetTriple().setOS(llvm::Triple::OSType::Linux);
     }
-    // Process NetBSD ELF notes.
+    // Process NetBSD ELF executables and shared libraries
     else if ((note.n_name == LLDB_NT_OWNER_NETBSD) &&
-             (note.n_type == LLDB_NT_NETBSD_ABI_TAG) &&
-             (note.n_descsz == LLDB_NT_NETBSD_ABI_SIZE)) {
-      // Pull out the min version info.
+             (note.n_type == LLDB_NT_NETBSD_NT_NETBSD_IDENT_TAG) &&
+             (note.n_descsz == LLDB_NT_NETBSD_NT_NETBSD_IDENT_DESCSZ) &&
+             (note.n_namesz == LLDB_NT_NETBSD_NT_NETBSD_IDENT_NAMESZ)) {
+      // Pull out the version info.
       uint32_t version_info;
       if (data.GetU32(&offset, &version_info, 1) == nullptr) {
         error.SetErrorString("failed to read NetBSD ABI note payload");
         return error;
       }
-
+      // Convert the version info into a major/minor/patch number.
+      //     #define __NetBSD_Version__ MMmmrrpp00
+      //
+      //     M = major version
+      //     m = minor version; a minor number of 99 indicates current.
+      //     r = 0 (since NetBSD 3.0 not used)
+      //     p = patchlevel
+      const uint32_t version_major = version_info / 100000000;	
+      const uint32_t version_minor = (version_info % 100000000) / 1000000;
+      const uint32_t version_patch = (version_info % 10000) / 100;
+      char os_name[32];
+      snprintf(os_name, sizeof(os_name),
+               "netbsd%" PRIu32 ".%" PRIu32 ".%" PRIu32, version_major,
+               version_minor, version_patch);
+      // Set the elf OS version to NetBSD.  Also clear the vendor.
+      arch_spec.GetTriple().setOSName(os_name);
+      arch_spec.GetTriple().setVendor(llvm::Triple::VendorType::UnknownVendor);
+    }
+    // Process NetBSD ELF core(5) notes
+    else if ((note.n_name == LLDB_NT_OWNER_NETBSDCORE) &&
+             (note.n_type == LLDB_NT_NETBSD_NT_PROCINFO)) {
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
