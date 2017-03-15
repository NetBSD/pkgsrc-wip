$NetBSD$

Conditionally compile netgraph call

--- vrrp_signal.c.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_signal.c
@@ -60,7 +60,9 @@ vrrp_signal_quit(int sig)
 	struct ether_addr ethaddr;
 
 	vrrp_thread_mutex_lock();
+#if defined (__FreeBSD__)
 	vrrp_netgraph_shutdown_allnodes();
+#endif	
 	while (vr_ptr[cpt]) {
 		ethaddr = vrrp_list_get_first(vr_ptr[cpt]);
 		vrrp_interface_vripaddr_delete(vr_ptr[cpt]);
