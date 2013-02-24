$NetBSD: patch-opensync_client_opensync__client__proxy.c,v 1.1 2013/02/24 13:41:22 othyro Exp $

Cast NULL as (char *).

--- opensync/client/opensync_client_proxy.c.orig	2009-09-20 20:14:18.000000000 +0000
+++ opensync/client/opensync_client_proxy.c
@@ -1032,12 +1032,12 @@ osync_bool osync_client_proxy_spawn(OSyn
 					//execlp("osplugin", "osplugin", osync_group_get_configdir(osync_member_get_group(osync_proxy_get_member(proxy)), memberstring, NULL);
 					readfd = osync_strdup_printf("%i", osync_queue_get_fd(read1));
 					writefd = osync_strdup_printf("%i", osync_queue_get_fd(write2));
-					execlp(OSPLUGIN, "osplugin", "-f", readfd, writefd, NULL);
+					execlp(OSPLUGIN, "osplugin", "-f", readfd, writefd, (char *)NULL);
 
 					if (errno == ENOENT) {
 						osync_trace(TRACE_INTERNAL, "Unable to find osplugin. Trying local path.");
 						//execlp("osplugin", "osplugin", osync_group_get_configdir(osync_member_get_group(osync_proxy_get_member(proxy)), memberstring, NULL);
-						execlp("./osplugin", "osplugin", "-f", readfd, writefd, NULL);
+						execlp("./osplugin", "osplugin", "-f", readfd, writefd, (char *)NULL);
 					}
 											
 					osync_trace(TRACE_INTERNAL, strerror(errno));
