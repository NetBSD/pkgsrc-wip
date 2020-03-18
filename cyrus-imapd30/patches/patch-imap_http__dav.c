$NetBSD$

The CalDAV / CardDAV functionality of Cyrus IMAP supports the
auto-discovery mechanism, which is used by many clients to find out
the calendars and address books available for the respective user.
At the moment this does not work for shared calendars and address
books from other users.

There was a discussion on this topic on Github:

    https://github.com/cyrusimap/cyrus-imapd/issues/2373

As part of the discussion, Дилян Палаузов provided a patch that
solves this problem. Unfortunately, it has not yet been included
in an official release because it may not yet be the complete solution
that covers all scenarios.

Anyway - the patch is included here because, in my opinion, sharing
calendars and address books is an essential functionality of a
groupware. Without this patch, this will not work on clients that only
offer auto-discovery - i.e. most mobile devices.

--- imap/http_dav.c.orig	2020-03-18 20:29:25.102243914 +0000
+++ imap/http_dav.c
@@ -5455,7 +5455,7 @@ int propfind_by_collection(const mbentry

     if (!fctx->req_tgt->resource) {
         len = make_collection_url(&writebuf, fctx->req_tgt->namespace->prefix,
-                                  mboxname, fctx->req_tgt->userid, NULL);
+                                  mboxname, mbname_userid(mbname_from_intname(mboxname)), NULL);

         /* copy it all back into place... in theory we should check against
          * 'last' and make sure it doesn't change from the original request.
@@ -5483,6 +5483,12 @@ int propfind_by_collection(const mbentry
     return r;
 }

+static int wrapper_propfind_by_collection(struct findall_data *data, void* rock) {
+    if (!data || !data->mbentry) return 0;
+    struct propfind_ctx *fctx = (struct propfind_ctx *) rock;
+    if ((httpd_myrights(httpd_authstate, data->mbentry) & DACL_READ != DACL_READ)) return 0;
+    return propfind_by_collection(data->mbentry, fctx);
+}

 /* Perform a PROPFIND request */
 EXPORTED int meth_propfind(struct transaction_t *txn, void *params)
@@ -5746,12 +5752,13 @@ EXPORTED int meth_propfind(struct transa
             else if (txn->req_tgt.mbentry) {
                 /* Add responses for all contained collections */
                 fctx.prefer &= ~PREFER_NOROOT;
-                mboxlist_mboxtree(txn->req_tgt.mbentry->name,
-                                  propfind_by_collection, &fctx,
-                                  MBOXTREE_SKIP_ROOT);

                 switch (txn->req_tgt.namespace->id) {
                 case URL_NS_DRIVE:
+                    mboxlist_mboxtree(txn->req_tgt.mbentry->name,
+                                  propfind_by_collection, &fctx,
+                                  MBOXTREE_SKIP_ROOT);
+
                     if (txn->req_tgt.flags == TGT_DRIVE_ROOT) {
                         /* Add a response for 'user' hierarchy */
                         buf_setcstr(&fctx.buf, txn->req_tgt.namespace->prefix);
@@ -5772,11 +5779,16 @@ EXPORTED int meth_propfind(struct transa
                     /* Fall through */

                 case URL_NS_ADDRESSBOOK:
+                    {
                     /* Add responses for shared collections */
-                    mboxlist_usersubs(txn->req_tgt.userid,
-                                      propfind_by_collection, &fctx,
-                                      MBOXTREE_SKIP_PERSONAL);
+                    const char *conf_str = txn->req_tgt.namespace->id == URL_NS_CALENDAR ?
+                        config_getstring(IMAPOPT_CALENDARPREFIX) : config_getstring(IMAPOPT_ADDRESSBOOKPREFIX);
+                    char *pat = malloc(5 + strlen(conf_str));
+                    sprintf(pat, "*%s%c*", conf_str, httpd_namespace.hier_sep);
+                    mboxlist_findall(&httpd_namespace, pat, httpd_userisadmin, txn->req_tgt.userid, httpd_authstate, wrapper_propfind_by_collection, &fctx);
+                    free(pat);
                     break;
+                    }
                 }
             }
