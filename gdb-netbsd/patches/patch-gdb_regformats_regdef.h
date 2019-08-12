$NetBSD$

--- gdb/regformats/regdef.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/regformats/regdef.h
@@ -19,15 +19,15 @@
 #ifndef REGFORMATS_REGDEF_H
 #define REGFORMATS_REGDEF_H
 
-struct reg
+struct xreg
 {
-  reg (int _offset)
+  xreg (int _offset)
     : name (""),
       offset (_offset),
       size (0)
   {}
 
-  reg (const char *_name, int _offset, int _size)
+  xreg (const char *_name, int _offset, int _size)
     : name (_name),
       offset (_offset),
       size (_size)
@@ -47,14 +47,14 @@ struct reg
   /* The size (in bits) of the value of this register, as transmitted.  */
   int size;
 
-  bool operator== (const reg &other) const
+  bool operator== (const xreg &other) const
   {
     return (strcmp (name, other.name) == 0
 	    && offset == other.offset
 	    && size == other.size);
   }
 
-  bool operator!= (const reg &other) const
+  bool operator!= (const xreg &other) const
   {
     return !(*this == other);
   }
