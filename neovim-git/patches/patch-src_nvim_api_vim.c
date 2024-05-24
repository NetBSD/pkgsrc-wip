$NetBSD$

- avoid conflict with NetBSD's popcount(3)

--- src/nvim/api/vim.c.orig	2024-05-23 22:45:05.813497933 +0000
+++ src/nvim/api/vim.c
@@ -2385,7 +2385,7 @@ void nvim__redraw(Dict(redraw) *opts, Er
   }
 
   int count = (win != NULL) + (buf != NULL);
-  VALIDATE(popcount(opts->is_set__redraw_) > count, "%s", "at least one action required", {
+  VALIDATE(spopcount64(opts->is_set__redraw_) > count, "%s", "at least one action required", {
     return;
   });
 
