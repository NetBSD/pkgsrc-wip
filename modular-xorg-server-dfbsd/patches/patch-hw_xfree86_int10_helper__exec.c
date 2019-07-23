$NetBSD$

--- hw/xfree86/int10/helper_exec.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/int10/helper_exec.c
@@ -676,6 +676,7 @@ bios_checksum(const uint8_t *start, int
 void
 LockLegacyVGA(xf86Int10InfoPtr pInt, legacyVGAPtr vga)
 {
+#if !defined(NO_LEGACY_VGA) || !defined(STRICT_XSRC_NETBSD)
     vga->save_msr = pci_io_read8(pInt->io, 0x03CC);
     vga->save_vse = pci_io_read8(pInt->io, 0x03C3);
 #ifndef __ia64__
@@ -688,17 +689,20 @@ LockLegacyVGA(xf86Int10InfoPtr pInt, leg
     pci_io_write8(pInt->io, 0x46E8, ~(uint8_t) 0x08 & vga->save_46e8);
 #endif
     pci_io_write8(pInt->io, 0x0102, ~(uint8_t) 0x01 & vga->save_pos102);
+#endif /* NO_LEGACY_VGA */
 }
 
 void
 UnlockLegacyVGA(xf86Int10InfoPtr pInt, legacyVGAPtr vga)
 {
+#if !defined(NO_LEGACY_VGA) || !defined(STRICT_XSRC_NETBSD)
     pci_io_write8(pInt->io, 0x0102, vga->save_pos102);
 #ifndef __ia64__
     pci_io_write8(pInt->io, 0x46E8, vga->save_46e8);
 #endif
     pci_io_write8(pInt->io, 0x03C3, vga->save_vse);
     pci_io_write8(pInt->io, 0x03C2, vga->save_msr);
+#endif /* NO_LEGACY_VGA */
 }
 
 #if defined (_PC)
