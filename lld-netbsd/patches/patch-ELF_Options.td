$NetBSD$

--- ELF/Options.td.orig	2019-03-14 17:35:11.000000000 +0000
+++ ELF/Options.td
@@ -320,6 +320,8 @@ defm symbol_ordering_file:
 
 defm sysroot: Eq<"sysroot", "Set the system root">;
 
+defm target: Eq<"target", "Apply configuration defaults for a given target">;
+
 def target1_rel: F<"target1-rel">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_REL32">;
 
 def target1_abs: F<"target1-abs">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_ABS32 (default)">;
