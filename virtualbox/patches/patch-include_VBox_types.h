$NetBSD$

--- include/VBox/types.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/types.h
@@ -75,7 +75,7 @@ typedef SUPSEMEVENTMULTI                
 
 
 /** Pointer to a VM. */
-typedef struct VM                  *PVM;
+typedef struct VM                  *vbox_PVM;
 /** Pointer to a VM - Ring-0 Ptr. */
 typedef R0PTRTYPE(struct VM *)      PVMR0;
 /** Pointer to a VM - Ring-3 Ptr. */
