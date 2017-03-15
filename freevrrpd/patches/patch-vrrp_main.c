$NetBSD$

Conditionally compile netgraph calls

--- vrrp_main.c.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_main.c
@@ -104,20 +104,22 @@ vrrp_main_post_init(struct vrrp_vr * vr,
 		syslog(LOG_CRIT, "exiting...");
 		exit(-1);
 	}
-
+#if defined (__FreeBSD__)
 	rc = vrrp_netgraph_bridge_create(vr->vr_if->if_name);
+#endif	
 	if ((rc < 0) && (errno != EEXIST)) {
 		syslog(LOG_CRIT, "cannot create a bridge device: %s", strerror(errno));
 		syslog(LOG_CRIT, "aborting...");
 		exit(-1);
 	}
+#if defined (__FreeBSD__)
 	rc = vrrp_netgraph_create_virtualiface(vr);
 	if (rc < 0) {
 		syslog(LOG_CRIT, "cannot create a virtual interface via netgraph: %s\n", strerror(errno));
 		syslog(LOG_CRIT, "check that ng_socket, ng_ether, ng_eiface and ng_bridge are loaded\n");
 		exit(-1);
 	}
-
+#endif
 	return;
 }
 
