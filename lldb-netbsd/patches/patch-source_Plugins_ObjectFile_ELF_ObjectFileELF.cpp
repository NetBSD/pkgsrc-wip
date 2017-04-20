$NetBSD$

--- source/Plugins/ObjectFile/ELF/ObjectFileELF.cpp.orig	2017-04-07 18:27:43.000000000 +0000
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
@@ -288,14 +291,15 @@ static uint32_t kalimbaVariantFromElfFla
   return kal_arch_variant;
 }
 
-static uint32_t mipsVariantFromElfFlags (const elf::ELFHeader &header) {
+static uint32_t mipsVariantFromElfFlags(const elf::ELFHeader &header) {
   const uint32_t mips_arch = header.e_flags & llvm::ELF::EF_MIPS_ARCH;
   uint32_t endian = header.e_ident[EI_DATA];
   uint32_t arch_variant = ArchSpec::eMIPSSubType_unknown;
   uint32_t fileclass = header.e_ident[EI_CLASS];
 
-  // If there aren't any elf flags available (e.g core elf file) then return default 
-  // 32 or 64 bit arch (without any architecture revision) based on object file's class.
+  // If there aren't any elf flags available (e.g core elf file) then return
+  // default 32 or 64 bit arch (without any architecture revision) based on
+  // object file's class.
   if (header.e_type == ET_CORE) {
     switch (fileclass) {
     case llvm::ELF::ELFCLASS32:
@@ -404,8 +408,8 @@ ObjectFile *ObjectFileELF::CreateInstanc
                                           lldb::offset_t file_offset,
                                           lldb::offset_t length) {
   if (!data_sp) {
-    data_sp =
-        DataBufferLLVM::CreateSliceFromPath(file->GetPath(), length, file_offset);
+    data_sp = DataBufferLLVM::CreateSliceFromPath(file->GetPath(), length,
+                                                  file_offset);
     if (!data_sp)
       return nullptr;
     data_offset = 0;
@@ -422,8 +426,8 @@ ObjectFile *ObjectFileELF::CreateInstanc
 
   // Update the data to contain the entire file if it doesn't already
   if (data_sp->GetByteSize() < length) {
-    data_sp =
-        DataBufferLLVM::CreateSliceFromPath(file->GetPath(), length, file_offset);
+    data_sp = DataBufferLLVM::CreateSliceFromPath(file->GetPath(), length,
+                                                  file_offset);
     if (!data_sp)
       return nullptr;
     data_offset = 0;
@@ -681,7 +685,7 @@ size_t ObjectFileELF::GetModuleSpecifica
           // with a bigger data source to get the actual values.
           size_t section_header_end = header.e_shoff + header.e_shentsize;
           if (header.HasHeaderExtension() &&
-            section_header_end > data_sp->GetByteSize()) {
+              section_header_end > data_sp->GetByteSize()) {
             data_sp = DataBufferLLVM::CreateSliceFromPath(
                 file.GetPath(), section_header_end, file_offset);
             if (data_sp) {
@@ -767,8 +771,8 @@ size_t ObjectFileELF::GetModuleSpecifica
                     CalculateELFNotesSegmentsCRC32(program_headers, data);
               } else {
                 // Need to map entire file into memory to calculate the crc.
-                data_sp = DataBufferLLVM::CreateSliceFromPath(file.GetPath(), -1,
-                                                         file_offset);
+                data_sp = DataBufferLLVM::CreateSliceFromPath(file.GetPath(),
+                                                              -1, file_offset);
                 if (data_sp) {
                   data.SetData(data_sp);
                   gnu_debuglink_crc = calc_gnu_debuglink_crc32(
@@ -1370,25 +1374,41 @@ ObjectFileELF::RefineModuleDetailsFromNo
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
+      // Pull out the version info
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
+      //     r = 0 (*)
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
@@ -1465,7 +1485,8 @@ ObjectFileELF::RefineModuleDetailsFromNo
             return error;
           }
           llvm::StringRef path(cstr);
-          if (path.contains("/lib/x86_64-linux-gnu") || path.contains("/lib/i386-linux-gnu")) {
+          if (path.contains("/lib/x86_64-linux-gnu") ||
+              path.contains("/lib/i386-linux-gnu")) {
             arch_spec.GetTriple().setOS(llvm::Triple::OSType::Linux);
             break;
           }
@@ -1475,7 +1496,7 @@ ObjectFileELF::RefineModuleDetailsFromNo
           // In case of MIPSR6, the LLDB_NT_OWNER_GNU note is missing
           // for some cases (e.g. compile with -nostdlib)
           // Hence set OS to Linux
-          arch_spec.GetTriple().setOS(llvm::Triple::OSType::Linux); 
+          arch_spec.GetTriple().setOS(llvm::Triple::OSType::Linux);
       }
     }
 
@@ -1579,7 +1600,7 @@ size_t ObjectFileELF::GetSectionHeaderIn
     const uint32_t sub_type = subTypeFromElfHeader(header);
     arch_spec.SetArchitecture(eArchTypeELF, header.e_machine, sub_type,
                               header.e_ident[EI_OSABI]);
-    
+
     // Validate if it is ok to remove GetOsFromOSABI.
     // Note, that now the OS is determined based on EI_OSABI flag and
     // the info extracted from ELF notes (see RefineModuleDetailsFromNote).
@@ -2357,7 +2378,7 @@ unsigned ObjectFileELF::ParseSymbols(Sym
        * flag to check whether the symbol is microMIPS and then set the address
        * class
        * accordingly.
-      */
+       */
       const llvm::Triple::ArchType llvm_arch = arch.GetMachine();
       if (llvm_arch == llvm::Triple::mips ||
           llvm_arch == llvm::Triple::mipsel ||
@@ -3016,41 +3037,42 @@ void ObjectFileELF::ParseUnwindSymbols(S
   // it have to recalculate the index first.
   std::vector<Symbol> new_symbols;
 
-  eh_frame->ForEachFDEEntries([this, symbol_table, section_list, &new_symbols](
-      lldb::addr_t file_addr, uint32_t size, dw_offset_t) {
-    Symbol *symbol = symbol_table->FindSymbolAtFileAddress(file_addr);
-    if (symbol) {
-      if (!symbol->GetByteSizeIsValid()) {
-        symbol->SetByteSize(size);
-        symbol->SetSizeIsSynthesized(true);
-      }
-    } else {
-      SectionSP section_sp =
-          section_list->FindSectionContainingFileAddress(file_addr);
-      if (section_sp) {
-        addr_t offset = file_addr - section_sp->GetFileAddress();
-        const char *symbol_name = GetNextSyntheticSymbolName().GetCString();
-        uint64_t symbol_id = symbol_table->GetNumSymbols();
-        Symbol eh_symbol(
-            symbol_id,       // Symbol table index.
-            symbol_name,     // Symbol name.
-            false,           // Is the symbol name mangled?
-            eSymbolTypeCode, // Type of this symbol.
-            true,            // Is this globally visible?
-            false,           // Is this symbol debug info?
-            false,           // Is this symbol a trampoline?
-            true,            // Is this symbol artificial?
-            section_sp,      // Section in which this symbol is defined or null.
-            offset,          // Offset in section or symbol value.
-            0,     // Size:          Don't specify the size as an FDE can
-            false, // Size is valid: cover multiple symbols.
-            false, // Contains linker annotations?
-            0);    // Symbol flags.
-        new_symbols.push_back(eh_symbol);
-      }
-    }
-    return true;
-  });
+  eh_frame->ForEachFDEEntries(
+      [this, symbol_table, section_list,
+       &new_symbols](lldb::addr_t file_addr, uint32_t size, dw_offset_t) {
+        Symbol *symbol = symbol_table->FindSymbolAtFileAddress(file_addr);
+        if (symbol) {
+          if (!symbol->GetByteSizeIsValid()) {
+            symbol->SetByteSize(size);
+            symbol->SetSizeIsSynthesized(true);
+          }
+        } else {
+          SectionSP section_sp =
+              section_list->FindSectionContainingFileAddress(file_addr);
+          if (section_sp) {
+            addr_t offset = file_addr - section_sp->GetFileAddress();
+            const char *symbol_name = GetNextSyntheticSymbolName().GetCString();
+            uint64_t symbol_id = symbol_table->GetNumSymbols();
+            Symbol eh_symbol(
+                symbol_id,       // Symbol table index.
+                symbol_name,     // Symbol name.
+                false,           // Is the symbol name mangled?
+                eSymbolTypeCode, // Type of this symbol.
+                true,            // Is this globally visible?
+                false,           // Is this symbol debug info?
+                false,           // Is this symbol a trampoline?
+                true,            // Is this symbol artificial?
+                section_sp, // Section in which this symbol is defined or null.
+                offset,     // Offset in section or symbol value.
+                0,     // Size:          Don't specify the size as an FDE can
+                false, // Size is valid: cover multiple symbols.
+                false, // Contains linker annotations?
+                0);    // Symbol flags.
+            new_symbols.push_back(eh_symbol);
+          }
+        }
+        return true;
+      });
 
   for (const Symbol &s : new_symbols)
     symbol_table->AddSymbol(s);
