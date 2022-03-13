$NetBSD$

* fix deadlock in split_path, from upstream
https://github.com/imageworks/pystring/issues/20
https://github.com/imageworks/pystring/pull/24

--- pystring.cpp.orig	2022-03-13 08:47:35.684732958 +0000
+++ pystring.cpp
@@ -1361,7 +1361,7 @@ namespace path
         while(!head2.empty() && ((pystring::slice(head2,-1) == "/") ||
                                  (pystring::slice(head2,-1) == "\\")))
         {
-            head2 = pystring::slice(head,0,-1);
+            head2 = pystring::slice(head2,0,-1);
         }
         
         if(!head2.empty()) head = head2;
