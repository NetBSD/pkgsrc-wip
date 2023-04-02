$NetBSD$

--- ld/emultempl/riscvelf.em.orig	2023-01-14 00:00:00.000000000 +0000
+++ ld/emultempl/riscvelf.em
@@ -26,6 +26,21 @@ fragment <<EOF
 #include "elfxx-riscv.h"
 
 static void
+gld${EMULATION_NAME}_before_parse (void)
+{
+  ldfile_set_output_arch ("riscv", bfd_arch_riscv);
+  input_flags.dynamic = true;
+  config.has_shared = true;
+  config.separate_code = false;
+  link_info.check_relocs_after_open_input = true;
+  link_info.relro = DEFAULT_LD_Z_RELRO;
+  link_info.separate_code = DEFAULT_LD_Z_SEPARATE_CODE;
+  link_info.warn_execstack = DEFAULT_LD_WARN_EXECSTACK;
+  link_info.no_warn_rwx_segments = ! DEFAULT_LD_WARN_RWX_SEGMENTS;
+  link_info.default_execstack = DEFAULT_LD_EXECSTACK;
+}
+
+static void
 riscv_elf_before_allocation (void)
 {
   gld${EMULATION_NAME}_before_allocation ();
@@ -100,6 +115,7 @@ riscv_create_output_section_statements (
 
 EOF
 
+LDEMUL_BEFORE_PARSE=gld${EMULATION_NAME}_before_parse
 LDEMUL_BEFORE_ALLOCATION=riscv_elf_before_allocation
 LDEMUL_AFTER_ALLOCATION=gld${EMULATION_NAME}_after_allocation
 LDEMUL_CREATE_OUTPUT_SECTION_STATEMENTS=riscv_create_output_section_statements
