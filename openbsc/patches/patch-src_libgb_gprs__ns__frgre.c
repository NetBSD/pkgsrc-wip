$NetBSD: patch-src_libgb_gprs__ns__frgre.c,v 1.1 2011/08/02 23:05:26 khorben Exp $

--- src/libgb/gprs_ns_frgre.c.orig	2011-03-05 14:16:19.000000000 +0000
+++ src/libgb/gprs_ns_frgre.c
@@ -28,6 +28,9 @@
 
 #include <sys/socket.h>
 #include <netinet/in.h>
+#ifdef __NetBSD__
+# include <netinet/in_systm.h>
+#endif
 #include <netinet/ip.h>
 #include <arpa/inet.h>
 
@@ -52,6 +55,7 @@ struct gre_hdr {
 static int handle_rx_gre_ipv4(struct bsc_fd *bfd, struct msgb *msg,
 				struct iphdr *iph, struct gre_hdr *greh)
 {
+#ifdef __linux__
 	struct gprs_ns_inst *nsi = bfd->data;
 	int gre_payload_len;
 	struct iphdr *inner_iph;
@@ -99,11 +103,16 @@ static int handle_rx_gre_ipv4(struct bsc
 	return sendto(nsi->frgre.fd.fd, inner_greh,
 		      gre_payload_len - inner_iph->ihl*4, 0,
 		      (struct sockaddr *)&daddr, sizeof(daddr));
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
 }
 
 static struct msgb *read_nsfrgre_msg(struct bsc_fd *bfd, int *error,
 					struct sockaddr_in *saddr)
 {
+#ifdef __linux__
 	struct msgb *msg = msgb_alloc(NS_ALLOC_SIZE, "Gb/NS/FR/GRE Rx");
 	int ret = 0;
 	socklen_t saddr_len = sizeof(*saddr);
@@ -198,6 +207,10 @@ static struct msgb *read_nsfrgre_msg(str
 out_err:
 	msgb_free(msg);
 	return NULL;
+#else
+	*error = ENOSYS;
+	return NULL;
+#endif
 }
 
 int gprs_ns_rcvmsg(struct gprs_ns_inst *nsi, struct msgb *msg,
