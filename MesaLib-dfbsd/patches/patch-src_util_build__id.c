$NetBSD$

Patch taken from FreeBSD ports graphics/mesa-dri mesa 17.1.0.

# Elf_ doesn't exist, use Elf32_ or Elf64_.

--- src/util/build_id.c.orig	2017-05-25 07:13:13.000000000 +0000
+++ src/util/build_id.c
@@ -33,7 +33,15 @@
 #endif
 
 #ifndef ElfW
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#ifdef __LP64__
+#define ElfW(type) Elf64_##type
+#else
+#define ElfW(type) Elf32_##type
+#endif /* __LP64__ */
+#else
 #define ElfW(type) Elf_##type
+#endif /* __FreeBSD__ || __DragonFly__ */
 #endif
 
 #define ALIGN(val, align)      (((val) + (align) - 1) & ~((align) - 1))
