$NetBSD: patch-regrename.c,v 1.1 2004/01/14 20:38:23 johnrshannon Exp $

--- gcc/regrename.c.orig	2004-01-14 09:25:09.000000000 -0700
+++ gcc/regrename.c
@@ -1345,8 +1345,8 @@ find_oldest_value_reg (enum reg_class cl
 	if (!TEST_HARD_REG_BIT (reg_class_contents[class], last))
 	  return NULL_RTX;
 
-      if (new = maybe_mode_change (oldmode, vd->e[regno].mode, mode, i,
-				   regno))
+      if ((new = maybe_mode_change (oldmode, vd->e[regno].mode, mode, i,
+				   regno)))
 	{
 	  ORIGINAL_REGNO (new) = ORIGINAL_REGNO (reg);
 	  REG_ATTRS (new) = REG_ATTRS (reg);
