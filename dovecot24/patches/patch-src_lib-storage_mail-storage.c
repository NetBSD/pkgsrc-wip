$NetBSD$

Don't drop the "RECENT" flag from messages automatically.
In terms of Mutt, this prevents that mails change from N to O state.
(Rhialto local patch)

--- src/lib-storage/mail-storage.c.orig	2026-02-07 14:20:14.590842703 +0000
+++ src/lib-storage/mail-storage.c
@@ -1109,6 +1109,8 @@ struct mailbox *mailbox_alloc(struct mai
 
 	i_assert(uni_utf8_str_is_valid(vname));
 
+	flags &= ~MAILBOX_FLAG_DROP_RECENT;
+
 	if (str_begins_icase(vname, "INBOX", &suffix) &&
 	    !str_begins_with(vname, "INBOX")) {
 		/* make sure INBOX shows up in uppercase everywhere. do this
@@ -1197,6 +1199,8 @@ struct mailbox *mailbox_alloc_guid(struc
 	enum mail_error open_error = MAIL_ERROR_TEMP;
 	const char *vname;
 
+	flags &= ~MAILBOX_FLAG_DROP_RECENT;
+
 	if (mailbox_guid_cache_find(list, guid, &vname) < 0) {
 		vname = NULL;
 	} else if (vname != NULL) {
