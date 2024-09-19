$NetBSD: patch-tools_osyncstress.c,v 1.1 2013/02/24 13:41:22 othyro Exp $

Don't continue the if block.

--- tools/osyncstress.c.orig	2009-09-20 20:14:18.000000000 +0000
+++ tools/osyncstress.c
@@ -184,7 +184,7 @@ void change_content(OSyncEngine *engine)
 					case 2:
 						if (osync_member_delete_data(meminfo->member, chinfo->change)) {
 							printf("Deleting data %s for member %lli. Objtype: %s Format: %s\n", osync_change_get_uid(chinfo->change), osync_member_get_id(meminfo->member), osync_objtype_get_name(osync_change_get_objtype(chinfo->change)), osync_objformat_get_name(osync_change_get_objformat(chinfo->change)));
-							if (!osync_group_get_slow_sync(engine->group, osync_objtype_get_name(osync_change_get_objtype(chinfo->change))));
+							if (!osync_group_get_slow_sync(engine->group, osync_objtype_get_name(osync_change_get_objtype(chinfo->change))))
 								chinfo->type = CHANGE_DELETED;
 						}
 						break;
