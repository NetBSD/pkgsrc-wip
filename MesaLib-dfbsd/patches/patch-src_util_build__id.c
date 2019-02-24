$NetBSD: patch-src_util_build__id.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Patch combining DragonFly dports and FreeBSD ports graphics/mesa-dri 18.2.0

--- src/util/build_id.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/util/build_id.c
@@ -35,7 +35,19 @@
 #endif
 
 #ifndef ElfW
+#if defined(__DragonFly__)
+#ifdef __LP64__
+#define ElfW(type) Elf64_##type
+#else
+#define ElfW(type) Elf32_##type
+#endif /* __LP64__ */
+#else
 #define ElfW(type) Elf_##type
+#endif /* __DragonFly__ */
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD__ < 12
+typedef Elf_Note Elf_Nhdr;
 #endif
 
 struct build_id_note {
