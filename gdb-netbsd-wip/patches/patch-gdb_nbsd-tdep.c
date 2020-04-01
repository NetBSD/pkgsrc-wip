$NetBSD$

--- gdb/nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/nbsd-tdep.c
@@ -3,9 +3,9 @@
    Copyright (C) 2002-2019 Free Software Foundation, Inc.
 
    Contributed by Wasabi Systems, Inc.
-  
+
    This file is part of GDB.
-  
+
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
@@ -20,6 +20,7 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include "defs.h"
+#include "objfiles.h"
 #include "solib-svr4.h"
 #include "nbsd-tdep.h"
 
@@ -47,3 +48,16 @@ nbsd_pc_in_sigtramp (CORE_ADDR pc, const
   return (func_name != NULL
 	  && startswith (func_name, "__sigtramp"));
 }
+
+CORE_ADDR
+nbsd_skip_solib_resolver (struct gdbarch *gdbarch, CORE_ADDR pc)
+{
+  struct bound_minimal_symbol msym;
+
+  msym = lookup_minimal_symbol("_rtld_bind_start", NULL, NULL);
+  if (msym.minsym && BMSYMBOL_VALUE_ADDRESS (msym) == pc)
+    return frame_unwind_caller_pc (get_current_frame ());
+  else
+    return find_solib_trampoline_target (get_current_frame (), pc);
+}
+
