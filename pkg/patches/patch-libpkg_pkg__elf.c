$NetBSD$

--- libpkg/pkg_elf.c.orig	2025-02-17 17:11:30.242681773 +0000
+++ libpkg/pkg_elf.c
@@ -414,10 +414,12 @@ elf_parse_arch(Elf *elf, GElf_Ehdr *ehdr
 	case EM_AARCH64:
 		return (PKG_ARCH_AARCH64);
 	case EM_ARM:
+#ifdef EF_ARM_EABIMASK
 		/* Only support EABI */
 		if ((ehdr->e_flags & EF_ARM_EABIMASK) == 0) {
 			return (PKG_ARCH_UNKNOWN);
 		}
+#endif
 
 		size_t shstrndx;
 		elf_getshdrstrndx(elf, &shstrndx);
