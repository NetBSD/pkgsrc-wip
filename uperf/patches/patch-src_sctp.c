$NetBSD$

Add NetBSD support.

--- src/sctp.c.orig	2017-09-11 12:26:20.000000000 +0000
+++ src/sctp.c
@@ -109,23 +109,29 @@ set_sctp_options(int fd, int family, flo
 #endif
 	}
 	if (f->sctp_max_burst_size > 0) {
+#ifdef SCTP_MAX_BURST
 		struct sctp_assoc_value maxburst;
 
 		memset(&maxburst, 0, sizeof(struct sctp_assoc_value));
 		maxburst.assoc_value = f->sctp_max_burst_size;
 		if (setsockopt(fd, IPPROTO_SCTP, SCTP_MAX_BURST,
-		               &maxburst, (socklen_t)sizeof(struct sctp_assoc_value)) < 0) {
+		               &maxburst, (socklen_t)sizeof(*maxburst)) < 0) {
 			uperf_log_msg(UPERF_LOG_WARN, errno,
 			              "Cannot set max. burst parameter for SCTP");
 		}
+#endif
 	}
 	if (f->sctp_max_fragment_size > 0) {
+#if defined(UPERF_NETBSD)
+		unsigned int maxfrag = f->sctp_max_fragment_size;
+#else
 		struct sctp_assoc_value maxfrag;
 
 		memset(&maxfrag, 0, sizeof(struct sctp_assoc_value));
 		maxfrag.assoc_value = f->sctp_max_fragment_size;
+#endif
 		if (setsockopt(fd, IPPROTO_SCTP, SCTP_MAXSEG,
-		               &maxfrag, (socklen_t)sizeof(struct sctp_assoc_value)) < 0) {
+		               &maxfrag, (socklen_t)sizeof(maxfrag)) < 0) {
 			uperf_log_msg(UPERF_LOG_WARN, errno,
 			              "Cannot set max. fragment size of SCTP");
 		}
@@ -135,7 +141,7 @@ set_sctp_options(int fd, int family, flo
 
 		memset(&param, 0, sizeof(struct sctp_paddrparams));
 		param.spp_address.ss_family = family;
-#if defined(UPERF_FREEBSD) || defined(UPERF_DARWIN)
+#if defined(UPERF_FREEBSD) || defined(UPERF_NETBSD) || defined(UPERF_DARWIN)
 		switch (family) {
 		case AF_INET:
 			param.spp_address.ss_len = sizeof(struct sockaddr_in);
@@ -302,13 +308,13 @@ protocol_sctp_write(protocol_t *p, void 
 		stream_no = flowops->sctp_stream_id;
 		if (strcasecmp(flowops->sctp_pr_policy, "ttl") == 0) {
 			timetolive = flowops->sctp_pr_value;
-#if defined(UPERF_FREEBSD) || defined(UPERF_DARWIN)
+#if defined(UPERF_FREEBSD) || defined(UPERF_NETBSD) || defined(UPERF_DARWIN)
 #ifdef SCTP_PR_SCTP_TTL
 			flags |= SCTP_PR_SCTP_TTL;
 #endif
 #endif
 		}
-#if defined(UPERF_FREEBSD) || defined(UPERF_DARWIN)
+#if defined(UPERF_FREEBSD) || defined(UPERF_NETBSD) || defined(UPERF_DARWIN)
 #ifdef SCTP_PR_SCTP_RTX
 		if (strcasecmp(flowops->sctp_pr_policy, "rtx") == 0) {
 			timetolive = flowops->sctp_pr_value;
