$NetBSD: patch-opal_mca_if_if.h,v 1.1 2013/11/05 22:34:15 asau Exp $

--- opal/mca/if/if.h.orig	2013-11-03 20:33:11.000000000 +0000
+++ opal/mca/if/if.h
@@ -82,6 +82,9 @@ BEGIN_C_DECLS
 #define DEFAULT_NUMBER_INTERFACES 10
 #define MAX_IFCONF_SIZE 10 * 1024 * 1024
 
+#ifdef if_mtu
+#undef if_mtu
+#endif
 
 typedef struct opal_if_t {
     opal_list_item_t     super;
