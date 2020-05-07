$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/bss_section.c.orig	2020-05-07 08:52:17.914676431 +0000
+++ runtime/druntime/src/rt/bss_section.c
@@ -10,7 +10,7 @@
 /* These symbols are defined in the linker script and bracket the
  * .bss, .lbss, .lrodata and .ldata sections.
  */
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 // Need to use weak linkage to workaround a bug in ld.bfd (Bugzilla 13025).
 extern int __attribute__((weak)) __bss_start, _end;
 
