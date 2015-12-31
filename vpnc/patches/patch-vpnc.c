$NetBSD: patch-vpnc.c,v 1.3 2014/02/20 20:54:00 hfath Exp $

--- vpnc.c.orig	2014-09-05 20:53:13.000000000 +0000
+++ vpnc.c
@@ -389,6 +389,8 @@ static void config_tunnel(struct sa_bloc
 {
 	setenv("VPNGATEWAY", inet_ntoa(s->dst), 1);
 	setenv("reason", "connect", 1);
+	setenv("DNS_UPDATE", config[CONFIG_DNS_UPDATE], 1);
+	setenv("TARGET_NETWORKS", config[CONFIG_TARGET_NETWORKS], 1);
 	system(config[CONFIG_SCRIPT]);
 	s_atexit_sa = s;
 	atexit(atexit_close);
@@ -1196,7 +1198,7 @@ static struct isakmp_payload *make_our_s
 
 static void lifetime_ike_process(struct sa_block *s, struct isakmp_attribute *a)
 {
-	uint32_t value;
+	uint32_t value = 0;
 
 	assert(a != NULL);
 	assert(a->type == IKE_ATTRIB_LIFE_TYPE);
@@ -1226,7 +1228,7 @@ static void lifetime_ike_process(struct 
 
 static void lifetime_ipsec_process(struct sa_block *s, struct isakmp_attribute *a)
 {
-	uint32_t value;
+	uint32_t value = 0;
 
 	assert(a != NULL);
 	assert(a->type == ISAKMP_IPSEC_ATTRIB_SA_LIFE_TYPE);
