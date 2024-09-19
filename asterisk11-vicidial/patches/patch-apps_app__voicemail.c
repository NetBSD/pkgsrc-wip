$NetBSD: patch-apps_app__voicemail.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- apps/app_voicemail.c.orig	2015-03-10 18:11:26.000000000 +0000
+++ apps/app_voicemail.c
@@ -5073,7 +5073,7 @@ static void make_email_file(FILE *p,
 		}
 		fprintf(p, "X-Asterisk-VM-Message-Type: %s" ENDL, msgnum > -1 ? "Message" : greeting_attachment);
 		fprintf(p, "X-Asterisk-VM-Orig-date: %s" ENDL, date);
-		fprintf(p, "X-Asterisk-VM-Orig-time: %ld" ENDL, (long) time(NULL));
+		fprintf(p, "X-Asterisk-VM-Orig-time: %jd" ENDL, (intmax_t) time(NULL));
 		fprintf(p, "X-Asterisk-VM-Message-ID: %s" ENDL, msg_id);
 	}
 	if (!ast_strlen_zero(cidnum)) {
@@ -5999,7 +5999,7 @@ static void generate_msg_id(char *dst)
 	 * but only in single system solutions.
 	 */
 	unsigned int unique_counter = ast_atomic_fetchadd_int(&msg_id_incrementor, +1);
-	snprintf(dst, MSG_ID_LEN, "%ld-%08x", (long) time(NULL), unique_counter);
+	snprintf(dst, MSG_ID_LEN, "%jd-%08x", (intmax_t) time(NULL), unique_counter);
 }
 
 /*!
@@ -6121,7 +6121,7 @@ static int msg_create_from_file(struct a
 			"callerchan=%s\n"
 			"callerid=%s\n"
 			"origdate=%s\n"
-			"origtime=%ld\n"
+			"origtime=%jd\n"
 			"category=%s\n"
 			"msg_id=%s\n"
 			"flag=\n" /* flags not supported in copy from file yet */
@@ -6134,7 +6134,7 @@ static int msg_create_from_file(struct a
 			recdata->call_priority,
 			S_OR(recdata->call_callerchan, "Unknown"),
 			S_OR(recdata->call_callerid, "Unknown"),
-			date, (long) time(NULL),
+			date, (intmax_t) time(NULL),
 			S_OR(category, ""),
 			msg_id,
 			duration);
@@ -6643,7 +6643,7 @@ static int leave_voicemail(struct ast_ch
 		/* Store information in real-time storage */
 		if (ast_check_realtime("voicemail_data")) {
 			snprintf(priority, sizeof(priority), "%d", ast_channel_priority(chan));
-			snprintf(origtime, sizeof(origtime), "%ld", (long) time(NULL));
+			snprintf(origtime, sizeof(origtime), "%jd", (intmax_t) time(NULL));
 			get_date(date, sizeof(date));
 			ast_callerid_merge(callerid, sizeof(callerid),
 				S_COR(ast_channel_caller(chan)->id.name.valid, ast_channel_caller(chan)->id.name.str, NULL),
@@ -6687,7 +6687,7 @@ static int leave_voicemail(struct ast_ch
 				"callerchan=%s\n"
 				"callerid=%s\n"
 				"origdate=%s\n"
-				"origtime=%ld\n"
+				"origtime=%jd\n"
 				"category=%s\n"
 				"msg_id=%s\n",
 				ext,
@@ -6699,7 +6699,7 @@ static int leave_voicemail(struct ast_ch
 				ast_channel_priority(chan),
 				ast_channel_name(chan),
 				callerid,
-				date, (long) time(NULL),
+				date, (intmax_t) time(NULL),
 				category ? category : "",
 				msg_id);
 		} else {
