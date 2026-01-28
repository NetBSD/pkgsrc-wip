$NetBSD$

Added missing extern declaration

--- v_dpi.c.orig	2023-07-16 21:42:51.000000000 +0000
+++ v_dpi.c
@@ -247,6 +247,7 @@ static char *map_ver_svtyp_to_ctypnam(ch
 static int32 get_ver_side_svtyp(struct net_t *);
 
 /* extern prototypes (maybe defined in this module) */
+extern void __add_dmpv_chglst_el_sel(struct net_t *, int32);
 extern void __chk_1tsk_dpi(struct task_t *);
 extern void __chk_funcdef_dpi(struct task_t *);
 
