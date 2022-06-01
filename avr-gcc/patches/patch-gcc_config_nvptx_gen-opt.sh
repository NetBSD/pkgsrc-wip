$NetBSD$

Fix nonportable syntax in "[" command.

--- gcc/config/nvptx/gen-opt.sh.orig	2022-05-06 07:30:57.000000000 +0000
+++ gcc/config/nvptx/gen-opt.sh
@@ -56,7 +56,7 @@ EnumValue
 Enum(ptx_isa) String(sm_$sm) Value(PTX_ISA_SM$sm)
 EOF
 
-    if [ "$sm" == "$last" ]; then
+    if [ "$sm" = "$last" ]; then
 	# Don't end with trailing empty line.
 	continue
     fi
