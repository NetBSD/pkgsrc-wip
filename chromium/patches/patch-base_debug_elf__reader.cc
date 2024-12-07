$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/elf_reader.cc.orig	2024-12-03 23:30:04.199355600 +0000
+++ base/debug/elf_reader.cc
@@ -50,6 +50,10 @@ using Xword = Elf64_Xword;
 
 constexpr char kGnuNoteName[] = "GNU";
 
+#ifndef NT_GNU_BUILD_ID
+#define NT_GNU_BUILD_ID 3
+#endif
+
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
 // pointer to the start of the ELF image.
