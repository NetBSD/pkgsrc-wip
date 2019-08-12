$NetBSD$

--- gdb/gdbserver/tdesc.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbserver/tdesc.c
@@ -75,7 +75,7 @@ init_target_desc (struct target_desc *td
 	gdb_assert (regnum == 0 || regnum >= tdesc->reg_defs.size ());
 
 	if (regnum != 0)
-	  tdesc->reg_defs.resize (regnum, reg (offset));
+	  tdesc->reg_defs.resize (regnum, xreg (offset));
 
 	tdesc->reg_defs.emplace_back (treg->name.c_str (), offset,
 				      treg->bitsize);
