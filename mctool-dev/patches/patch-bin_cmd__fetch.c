$NetBSD$

In file included from cmd_fetch.c:47:
In function 'xferstart',
    inlined from 'cmd_common' at cmd_fetch.c:952:9:
/tmp/wip/mctool-dev/work/.buildlink/include/curl/typecheck-gcc.h:50:13: error: call to 'Wcurl_easy_setopt_err_long' declared with attribute warning: curl_easy_setopt expects a long argument [-Werror=attribute-warning]
   50 |             Wcurl_easy_setopt_err_long();                               \
      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/tmp/wip/mctool-dev/work/.buildlink/include/curl/curl.h:54:7: note: in definition of macro 'CURL_IGNORE_DEPRECATION'
   54 |       statements \
      |       ^~~~~~~~~~
cmd_fetch.c:244:24: note: in expansion of macro 'curl_easy_setopt'
  244 |                 cerr = curl_easy_setopt(X->handle, CURLOPT_FAILONERROR, 1);
      |                        ^~~~~~~~~~~~~~~~
/tmp/wip/mctool-dev/work/.buildlink/include/curl/typecheck-gcc.h:50:13: error: call to 'Wcurl_easy_setopt_err_long' declared with attribute warning: curl_easy_setopt expects a long argument [-Werror=attribute-warning]
   50 |             Wcurl_easy_setopt_err_long();                               \
      |             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/tmp/wip/mctool-dev/work/.buildlink/include/curl/curl.h:54:7: note: in definition of macro 'CURL_IGNORE_DEPRECATION'
   54 |       statements \
      |       ^~~~~~~~~~
cmd_fetch.c:249:24: note: in expansion of macro 'curl_easy_setopt'
  249 |                 cerr = curl_easy_setopt(X->handle, CURLOPT_FOLLOWLOCATION, 1);
      |                        ^~~~~~~~~~~~~~~~

--- bin/cmd_fetch.c.orig	2026-04-27 14:38:59.952317267 +0000
+++ bin/cmd_fetch.c
@@ -241,12 +241,12 @@ xferstart(struct cmd_fetch *F, struct distfile *D, con
 		 */
 		if ((X->handle = curl_easy_init()) == NULL)
 			errx(1, "curl_easy_init");
-		cerr = curl_easy_setopt(X->handle, CURLOPT_FAILONERROR, 1);
+		cerr = curl_easy_setopt(X->handle, CURLOPT_FAILONERROR, 1L);
 		if (cerr) {
 			errx(1, "curl_easy_setopt(CURLOPT_FAILONERROR): %s",
 			    curl_easy_strerror(cerr));
 		}
-		cerr = curl_easy_setopt(X->handle, CURLOPT_FOLLOWLOCATION, 1);
+		cerr = curl_easy_setopt(X->handle, CURLOPT_FOLLOWLOCATION, 1L);
 		if (cerr) {
 			errx(1, "curl_easy_setopt(CURLOPT_FOLLOWLOCATION): %s",
 			    curl_easy_strerror(cerr));
