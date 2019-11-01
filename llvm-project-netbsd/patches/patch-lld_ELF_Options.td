$NetBSD$

--- lld/ELF/Options.td.orig	2019-11-01 18:04:25.971104878 +0000
+++ lld/ELF/Options.td
@@ -168,6 +168,9 @@ defm filter: Eq<"filter", "Set DT_FILTER
 
 defm fini: Eq<"fini", "Specify a finalizer function">, MetaVarName<"<symbol>">;
 
+def fix_cortex_a53_835769: F<"fix-cortex-a53-835769">,
+  HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 835769">;
+
 def fix_cortex_a53_843419: F<"fix-cortex-a53-843419">,
   HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 843419">;
 
@@ -350,6 +353,8 @@ defm symbol_ordering_file:
 
 defm sysroot: Eq<"sysroot", "Set the system root">;
 
+defm target: Eq<"target", "Apply configuration defaults for a given target">;
+
 def target1_rel: F<"target1-rel">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_REL32">;
 
 def target1_abs: F<"target1-abs">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_ABS32 (default)">;
