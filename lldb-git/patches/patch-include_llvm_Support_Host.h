$NetBSD: patch-include_llvm_Support_Host.h,v 1.2 2014/01/19 14:06:41 ryoon Exp $

Fix lack of machine/endian.h on solaris
http://permalink.gmane.org/gmane.comp.compilers.llvm.devel/63225 

--- ../llvm/include/llvm/Support/Host.h.orig	2015-09-21 20:56:17.000000000 +0000
+++ ../llvm/include/llvm/Support/Host.h
@@ -18,6 +18,20 @@
 
 #if defined(__linux__) || defined(__GNU__)
 #include <endian.h>
+#elif defined(__sun) & defined(__SVR4)
+# ifndef BYTE_ORDER
+# define LITTLE_ENDIAN 1234
+# define BIG_ENDIAN 4321
+# if defined(__sun) & defined(__SVR4)
+# include <sys/isa_defs.h>
+# ifdef _LITTLE_ENDIAN
+# define BYTE_ORDER LITTLE_ENDIAN
+# endif
+# ifdef _BIG_ENDIAN
+# define BYTE_ORDER BIG_ENDIAN
+# endif
+# endif /* sun */
+# endif /* BYTE_ORDER */
 #else
 #if !defined(BYTE_ORDER) && !defined(LLVM_ON_WIN32)
 #include <machine/endian.h>
