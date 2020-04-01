$NetBSD$

--- gdb/objfiles.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/objfiles.c
@@ -1123,6 +1123,13 @@ static int
 insert_section_p (const struct bfd *abfd,
 		  const struct bfd_section *section)
 {
+#ifndef __NetBSD__
+  /*
+   * On NetBSD we don't typically have overlay sections and in some of
+   * our kernels (i386 vma = lma | 0xc0000000), so the following test
+   * makes kernels not load any symbols. There must be a better way to
+   * detect overlays.
+   */
   const bfd_vma lma = bfd_section_lma (abfd, section);
 
   if (overlay_debugging && lma != 0 && lma != bfd_section_vma (abfd, section)
@@ -1131,6 +1138,7 @@ insert_section_p (const struct bfd *abfd
        discarding sections from the "system supplied DSO" (aka vdso)
        on some Linux systems (e.g. Fedora 11).  */
     return 0;
+#endif
   if ((bfd_get_section_flags (abfd, section) & SEC_THREAD_LOCAL) != 0)
     /* This is a TLS section.  */
     return 0;
