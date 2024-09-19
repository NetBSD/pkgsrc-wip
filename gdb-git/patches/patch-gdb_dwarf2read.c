$NetBSD$

--- gdb/dwarf2read.c.orig	2017-09-11 11:24:04.000000000 +0000
+++ gdb/dwarf2read.c
@@ -22098,7 +22098,7 @@ dwarf_decode_macro_bytes (bfd *abfd,
 
       /* Note that we rely on the fact that the corresponding GNU and
 	 DWARF constants are the same.  */
-      switch (macinfo_type)
+      switch ((uint64_t)macinfo_type)
 	{
 	  /* A zero macinfo type indicates the end of the macro
 	     information.  */
@@ -22415,7 +22415,7 @@ dwarf_decode_macros (struct dwarf2_cu *c
 
       /* Note that we rely on the fact that the corresponding GNU and
 	 DWARF constants are the same.  */
-      switch (macinfo_type)
+      switch ((uint64_t)macinfo_type)
         {
           /* A zero macinfo type indicates the end of the macro
              information.  */
