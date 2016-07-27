$NetBSD$

--- listfuncs.c.orig	2016-07-27 09:01:17.575344491 +0000
+++ listfuncs.c
@@ -18,6 +18,9 @@ char listfuncs_RCSid[] = "Revision: 1.3 
 
 #include "agm.h"
 
+#include <stdlib.h>
+
+void
 destroy_list (ls, le)
     struct wnode *ls, *le;
 {
