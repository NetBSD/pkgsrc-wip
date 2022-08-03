$NetBSD$

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2022-06-22 16:46:24.000000000 +0000
+++ ELF/Config.h
@@ -170,6 +170,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool formatBinary = false;
