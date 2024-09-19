$NetBSD$

--- src/ccan/list/list.h.orig	2015-09-19 09:37:05.000000000 +0000
+++ src/ccan/list/list.h
@@ -6,8 +6,8 @@
 #include <ccan/container_of/container_of.h>
 #include <ccan/check_type/check_type.h>
 
-#undef LIST_HEAD
-#undef LIST_HEAD_INIT
+//#undef LIST_HEAD
+//#undef LIST_HEAD_INIT
 
 /**
  * struct list_node - an entry in a doubly-linked list
@@ -99,6 +99,7 @@ struct list_node *list_check_node(const 
 #define list_debug_node(n) (n)
 #endif
 
+#if 0
 /**
  * LIST_HEAD_INIT - initializer for an empty list_head
  * @name: the name of the list.
@@ -128,6 +129,7 @@ struct list_node *list_check_node(const 
  */
 #define LIST_HEAD(name) \
 	struct list_head name = LIST_HEAD_INIT(name)
+#endif
 
 /**
  * list_head_init - initialize a list_head
