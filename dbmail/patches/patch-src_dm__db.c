$NetBSD: patch-src_dm__db.c,v 1.1 2014/12/19 22:10:31 tnn2 Exp $

commit a0c2d6fe4684d3abde76d6428237feafdbe07ba9

--- src/dm_db.c.orig	2014-11-02 14:18:42.000000000 +0000
+++ src/dm_db.c
@@ -3695,6 +3695,8 @@ int db_user_validate(ClientBase_T *ci, c
 		else 
 			is_validated = (strcmp(dbpass, password) == 0) ? 1 : 0;
         }
+	else if (ci && ci->auth) // CRAM-MD5 auth but storage is encrypted
+		is_validated = 0;
 
 	else if (SMATCH(encode, "crypt")) {
 		TRACE(TRACE_DEBUG, "validating using crypt() encryption");
