$NetBSD$

Patch from FreeBSD ports libdrm 2.4.75.

--- src/intel_list.h.orig	2017-02-10 21:52:47.000000000 +0000
+++ src/intel_list.h
@@ -305,8 +305,10 @@ list_is_empty(const struct list *head)
 #define list_last_entry(ptr, type, member) \
     list_entry((ptr)->prev, type, member)
 
+#if !defined(__FreeBSD__)
 #define __container_of(ptr, sample, member)				\
     (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
+#endif
 /**
  * Loop through the list given by head and set pos to struct in the list.
  *
@@ -324,15 +326,29 @@ list_is_empty(const struct list *head)
  * @param member Member name of the struct list in the list elements.
  *
  */
+#if defined(__FreeBSD__)
+ #define list_for_each_entry(pos, head, member)				\
+    for (pos = NULL, pos = __container_of((head)->next, pos, member);	\
+ 	 &pos->member != (head);					\
+ 	 pos = __container_of(pos->member.next, pos, member))
+#else
 #define list_for_each_entry(pos, head, member)				\
     for (pos = __container_of((head)->next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.next, pos, member))
+#endif
 
+#if defined(__FreeBSD__)
+#define list_for_each_entry_reverse(pos, head, member)			\
+    for (pos = NULL, pos = __container_of((head)->prev, pos, member);	\
+ 	 &pos->member != (head);					\
+ 	 pos = __container_of(pos->member.prev, pos, member))
+#else
 #define list_for_each_entry_reverse(pos, head, member)				\
     for (pos = __container_of((head)->prev, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.prev, pos, member))
+#endif
 
 /**
  * Loop through the list, keeping a backup pointer to the element. This
@@ -341,11 +357,19 @@ list_is_empty(const struct list *head)
  *
  * See list_for_each_entry for more details.
  */
+#if defined(__FreeBSD__)
+#define list_for_each_entry_safe(pos, tmp, head, member)		\
+    for (pos = NULL, pos = __container_of((head)->next, pos, member),	\
+ 	 tmp = __container_of(pos->member.next, pos, member);		\
+ 	 &pos->member != (head);					\
+ 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
+#else
 #define list_for_each_entry_safe(pos, tmp, head, member)		\
     for (pos = __container_of((head)->next, pos, member),		\
 	 tmp = __container_of(pos->member.next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
+#endif
 
 #else
 
