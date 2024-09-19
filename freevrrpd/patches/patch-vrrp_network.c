$NetBSD$

Sort out preprocessor conditionals 

--- vrrp_network.c.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_network.c
@@ -312,10 +312,10 @@ vrrp_network_delete_local_route(struct i
 	rtm.rtm_version = RTM_VERSION;
 #ifdef __FreeBSD__
 	rtm.rtm_flags = RTF_UP | RTF_HOST | RTF_LOCAL;
-#endif
 #if __FreeBSD_version < 800059
 	rtm.rtm_flags |= RTF_WASCLONED;
 #endif
+#endif
 #ifdef __NetBSD__
 	rtm.rtm_flags = RTF_UP | RTF_HOST | RTF_CLONED;
 #endif
