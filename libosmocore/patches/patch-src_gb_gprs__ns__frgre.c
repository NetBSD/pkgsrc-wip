$NetBSD$

--- src/gb/gprs_ns_frgre.c.orig	2019-01-21 13:50:43.000000000 +0000
+++ src/gb/gprs_ns_frgre.c
@@ -91,6 +91,9 @@ struct iphdr
 #endif
 
 
+#if defined(__NetBSD__)
+#warning TODO
+#else
 /* IPv4 messages inside the GRE tunnel might be GRE keepalives */
 static int handle_rx_gre_ipv4(struct osmo_fd *bfd, struct msgb *msg,
 				struct iphdr *iph, struct gre_hdr *greh)
@@ -242,6 +245,7 @@ out_err:
 	msgb_free(msg);
 	return NULL;
 }
+#endif
 
 int gprs_ns_rcvmsg(struct gprs_ns_inst *nsi, struct msgb *msg,
 		   struct sockaddr_in *saddr, enum gprs_ns_ll ll);
