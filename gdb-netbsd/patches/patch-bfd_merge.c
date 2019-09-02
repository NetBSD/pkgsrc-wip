$NetBSD$

--- bfd/merge.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ bfd/merge.c
@@ -338,7 +338,7 @@ sec_merge_emit (bfd *abfd, struct sec_me
 
   /* Trailing alignment needed?  */
   off = sec->size - off;
-  if (off != 0)
+  if (pad != NULL && off != 0)
     {
       BFD_ASSERT (off <= pad_len);
       if (contents)
