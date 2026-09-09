$NetBSD$

Check for version 2 of sys/exec_elf.h, version_symbol has a different
type since version 2 of the header.

--- libraries/abseil/absl/debugging/internal/elf_mem_image.cc.orig	2026-08-28 22:25:23.000000000 +0000
+++ libraries/abseil/absl/debugging/internal/elf_mem_image.cc
@@ -378,7 +378,11 @@ void ElfMemImage::SymbolIterator::Update(uint32_t incr
   ABSL_RAW_CHECK(symbol && version_symbol, "");
   const char *const symbol_name = image->GetDynstr(symbol->st_name);
 #if defined(__NetBSD__)
+# if (( _SYS_EXEC_ELF_H_ + 0 ) < 2)
   const int version_index = version_symbol->vs_vers & VERSYM_VERSION;
+# else
+  const int version_index = (int)*version_symbol;
+#endif
 #else
   const ElfW(Versym) version_index = version_symbol[0] & VERSYM_VERSION;
 #endif
