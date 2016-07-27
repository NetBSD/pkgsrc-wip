$NetBSD$

--- process.c.orig	2016-07-27 09:17:40.620865989 +0000
+++ process.c
@@ -27,14 +27,11 @@ char process_RCSid[] = "Revision: 1.6 $"
 
 #include "agm.h"
 
-process (word, ls, le, minlen, maxw, depth)
+void
+process (char *word, struct vnode *ls, struct vnode *le, unsigned int minlen, unsigned int maxw, unsigned int depth)
     /* searches the list ls - le for words which can be extracted from
        word; if a word extracts exactly, the words in prevs are printed out,
        otherwise, a sublist is built, and process() called recursively */
-    char *word;
-    struct wnode *ls, *le;
-    unsigned int minlen;
-    unsigned int depth;
 {
   char newword[WORDLEN];
   struct wnode *loop;
