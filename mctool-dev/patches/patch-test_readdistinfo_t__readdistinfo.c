$NetBSD$

t_readdistinfo.c: In function 'main':
t_readdistinfo.c:71:29: error: 'calloc' sizes specified with 'sizeof' in the earlier argument and not in the later argument [-Werror=calloc-transposed-args]
   71 |         perm = calloc(sizeof(*perm), tab->dit_size);
      |                             ^
t_readdistinfo.c:71:29: note: earlier argument should specify number of elements, later size of each element

--- test/readdistinfo/t_readdistinfo.c.orig	2026-04-27 14:39:26.548386062 +0000
+++ test/readdistinfo/t_readdistinfo.c
@@ -68,7 +68,7 @@ main(int argc, char **argv)
 	tab = readdistinfo(argv[1], 0);
 	if (tab == NULL)
 		err(1, "read distinfo");
-	perm = calloc(sizeof(*perm), tab->dit_size);
+	perm = calloc(tab->dit_size, sizeof(*perm));
 	if (perm == NULL)
 		err(1, "calloc");
 	for (i = 0; i < tab->dit_size; i++)
