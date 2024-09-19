$NetBSD: patch-addons_chan__ooh323.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- addons/chan_ooh323.c.orig	2014-10-15 09:02:50.000000000 +0000
+++ addons/chan_ooh323.c
@@ -3950,7 +3950,7 @@ static void *do_monitor(void *data)
 				h323->lastrtprx + h323->rtptimeout < t) {
 				if (!ast_channel_trylock(h323->owner)) {
 					ast_softhangup_nolock(h323->owner, AST_SOFTHANGUP_DEV);
-					ast_log(LOG_NOTICE, "Disconnecting call '%s' for lack of RTP activity in %ld seconds\n", ast_channel_name(h323->owner), (long) (t - h323->lastrtprx));
+					ast_log(LOG_NOTICE, "Disconnecting call '%s' for lack of RTP activity in %jd seconds\n", ast_channel_name(h323->owner), (intmax_t) (t - h323->lastrtprx));
 					ast_channel_unlock(h323->owner);
 				}
 				
