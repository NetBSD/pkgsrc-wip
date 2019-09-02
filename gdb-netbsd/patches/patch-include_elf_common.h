$NetBSD$

--- include/elf/common.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ include/elf/common.h
@@ -686,6 +686,7 @@
    must start with "NetBSD-CORE".  */
 
 #define NT_NETBSDCORE_PROCINFO	1	/* Has a struct procinfo */
+#define NT_NETBSDCORE_AUXV	2	/* Has a copy of Elfxx_auxv_t */
 #define NT_NETBSDCORE_FIRSTMACH	32	/* start of machdep note types */
 
 
