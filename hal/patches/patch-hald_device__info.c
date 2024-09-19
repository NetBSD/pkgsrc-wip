$NetBSD$

--- hald/device_info.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/device_info.c
@@ -1110,8 +1110,15 @@ rules_match_and_merge_device (void *fdi_
 				/*HAL_INFO(("no match, skip to rule (%llx)", rule->jump_position));*/
 				rule = di_jump(rule);
 
+#if 0
+				/*
+				 * XXX
+				 * this fires when a node has a single child
+				 * which happens on some non-x86 machines
+				 */
 				if(rule == NULL)
 					DIE(("Rule is NULL on jump"));
+#endif
 
 				continue;
 			}
