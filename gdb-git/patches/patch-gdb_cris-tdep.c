$NetBSD$

--- gdb/cris-tdep.c.orig	2017-09-11 11:24:04.000000000 +0000
+++ gdb/cris-tdep.c
@@ -1434,7 +1434,7 @@ cris_spec_reg_applicable (struct gdbarch
       /* Indeterminate/obsolete.  */
       return 0;
     case cris_ver_v0_3:
-      return (version >= 0 && version <= 3);
+      return (version <= 3);
     case cris_ver_v3p:
       return (version >= 3);
     case cris_ver_v8:
@@ -1442,7 +1442,7 @@ cris_spec_reg_applicable (struct gdbarch
     case cris_ver_v8p:
       return (version >= 8);
     case cris_ver_v0_10:
-      return (version >= 0 && version <= 10);
+      return (version <= 10);
     case cris_ver_v3_10:
       return (version >= 3 && version <= 10);
     case cris_ver_v8_10:
