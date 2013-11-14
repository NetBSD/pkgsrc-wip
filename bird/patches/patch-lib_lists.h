$NetBSD: patch-lib_lists.h,v 1.1 2013/11/14 14:01:11 kralian Exp $

--- lib/lists.h.orig	2012-08-07 09:15:40.000000000 +0000
+++ lib/lists.h
@@ -48,19 +48,19 @@ typedef struct list {			/* In fact two o
 
 #define EMPTY_LIST(list) (!(list).head->next)
 
+#ifndef _BIRD_LISTS_C_
+#define LIST_INLINE static inline
+#include "lib/lists.c"
+#undef LIST_INLINE
+#else
+#define LIST_INLINE
+
 void add_tail(list *, node *);
 void add_head(list *, node *);
 void rem_node(node *);
 void add_tail_list(list *, list *);
 void init_list(list *);
 void insert_node(node *, node *);
-
-#ifndef _BIRD_LISTS_C_
-#define LIST_INLINE extern inline
-#include "lib/lists.c"
-#undef LIST_INLINE
-#else
-#define LIST_INLINE
 #endif
 
 #endif
