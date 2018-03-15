$NetBSD$

--- gum/backend-elf/gumelfmodule.c.orig	2018-03-12 19:53:33.000000000 +0000
+++ gum/backend-elf/gumelfmodule.c
@@ -505,6 +505,7 @@ gum_store_symtab_params (const GumElfDyn
 
       break;
     }
+#ifdef DT_GNU_HASH
     case DT_GNU_HASH:
     {
       const guint32 * hash_params;
@@ -551,6 +552,7 @@ gum_store_symtab_params (const GumElfDyn
 
       break;
     }
+#endif
     default:
       break;
   }
