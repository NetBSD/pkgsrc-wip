$NetBSD$

--- gdb/gdbserver/tdesc.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbserver/tdesc.h
@@ -31,7 +31,7 @@ struct target_desc : tdesc_element
 {
   /* A vector of elements of register definitions that
      describe the inferior's register set.  */
-  std::vector<struct reg> reg_defs;
+  std::vector<struct xreg> reg_defs;
 
   /* The register cache size, in bytes.  */
   int registers_size;
