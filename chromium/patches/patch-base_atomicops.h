$NetBSD: patch-base_atomicops.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/atomicops.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/atomicops.h
@@ -54,7 +54,11 @@ typedef intptr_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
+#if defined(OS_OPENBSD) && defined(__i386__)
+typedef Atomic32 AtomicWord;
+#else
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
