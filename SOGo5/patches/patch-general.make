$NetBSD$

Add missing linker flag objc in general.make because env or pkgsrc
LDFLAGS are not working.

--- general.make.orig	2022-01-18 16:19:17.000000000 +0000
+++ general.make
@@ -25,3 +25,7 @@ endif
 # readelf -p .GCC.command.line /path/to/elf_file
 ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
 
+# Ensure linking to objc works correctly. Because the
+# env or pkgsrc variable LDFLAGS isn't working it's
+# required configure it here:
+ADDITIONAL_LDFLAGS += -lobjc
