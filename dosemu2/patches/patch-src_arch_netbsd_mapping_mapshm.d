$NetBSD$

--- src/arch/netbsd/mapping/mapshm.d.orig	2017-11-02 06:34:44.097829234 +0000
+++ src/arch/netbsd/mapping/mapshm.d
@@ -0,0 +1,12 @@
+mapshm.o: mapshm.c ../../../../src/include/config.h \
+  ../../../../src/include/emu.h ../../../../src/include/types.h \
+  ../../../../src/include/cpu.h ../../../../src/include/pic.h \
+  ../../../../src/include/bios.h ../../../../src/include/memory.h \
+  ../../../../src/include/vm86_compat.h ../../../../src/include/priv.h \
+  ../../../../src/include/mouse.h \
+  ../../../../src/include/keyboard/keyboard.h \
+  ../../../../src/include/dosemu_config.h \
+  ../../../../src/plugin/include/plugin_config.h \
+  ../../../../src/include/translate/unicode_symbols.h \
+  ../../../../src/include/dosemu_debug.h \
+  ../../../../src/include/mapping.h
