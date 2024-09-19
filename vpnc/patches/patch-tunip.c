$NetBSD: patch-tunip.c,v 1.2 2014/02/20 20:53:59 hfath Exp $

--- tunip.c.orig	2014-09-05 20:53:13.000000000 +0000
+++ tunip.c
@@ -177,7 +177,8 @@ static int encap_rawip_recv(struct sa_bl
 		return -1;
 	}
 	if (r < (p->ip_hl << 2) + s->ipsec.em->fixed_header_size) {
-		logmsg(LOG_ALERT, "packet too short. got %zd, expected %d", r, (p->ip_hl << 2) + s->ipsec.em->fixed_header_size);
+		syslog(LOG_ALERT, "packet too short. got %ld, expected %ld",
+		    (long) r, (long) ((p->ip_hl << 2) + s->ipsec.em->fixed_header_size));
 		return -1;
 	}
 
@@ -216,8 +217,8 @@ static int encap_udp_recv(struct sa_bloc
 		return -1;
 	}
 	if (r < s->ipsec.em->fixed_header_size) {
-		logmsg(LOG_ALERT, "packet too short from %s. got %zd, expected %d",
-			inet_ntoa(s->dst), r, s->ipsec.em->fixed_header_size);
+		logmsg(LOG_ALERT, "packet too short from %s. got %ld, expected %ld",
+			inet_ntoa(s->dst), (long) r, (long) (s->ipsec.em->fixed_header_size));
 		return -1;
 	}
 
@@ -879,7 +880,7 @@ static void vpnc_main_loop(struct sa_blo
 				}
 			}
 			DEBUG(2,printf("lifetime status: %ld of %u seconds used, %u|%u of %u kbytes used\n",
-				time(NULL) - s->ipsec.life.start,
+				(long)(time(NULL) - s->ipsec.life.start),
 				s->ipsec.life.seconds,
 				s->ipsec.life.rx/1024,
 				s->ipsec.life.tx/1024,
