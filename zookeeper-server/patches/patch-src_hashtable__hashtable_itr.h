$NetBSD: patch-src_hashtable__hashtable_itr.h,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

Fix for SunOS.
--- src/c/src/hashtable/hashtable_itr.h.orig	2012-02-06 10:48:40.000000000 +0000
+++ src/c/src/hashtable/hashtable_itr.h
@@ -32,20 +32,36 @@ hashtable_iterator(struct hashtable *h);
 /* hashtable_iterator_key
  * - return the value of the (key,value) pair at the current position */
 
+#ifdef __sun
+static inline void *
+hashtable_iterator_key(struct hashtable_itr *i)
+{
+    return i->e->k;
+}
+#else
 extern inline void *
 hashtable_iterator_key(struct hashtable_itr *i)
 {
     return i->e->k;
 }
+#endif
 
 /*****************************************************************************/
 /* value - return the value of the (key,value) pair at the current position */
 
+#ifdef __sun
+static inline void *
+hashtable_iterator_value(struct hashtable_itr *i)
+{
+    return i->e->v;
+}
+#else
 extern inline void *
 hashtable_iterator_value(struct hashtable_itr *i)
 {
     return i->e->v;
 }
+#endif
 
 /*****************************************************************************/
 /* advance - advance the iterator to the next element
