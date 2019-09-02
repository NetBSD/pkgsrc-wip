$NetBSD$

--- bfd/elf.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ bfd/elf.c
@@ -10582,6 +10582,7 @@ elfcore_grok_netbsd_note (bfd *abfd, Elf
       /* On the Alpha, SPARC (32-bit and 64-bit), PT_GETREGS == mach+0 and
 	 PT_GETFPREGS == mach+2.  */
 
+    case bfd_arch_aarch64:
     case bfd_arch_alpha:
     case bfd_arch_sparc:
       switch (note->type)
