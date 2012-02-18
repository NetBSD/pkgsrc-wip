$NetBSD: patch-http__parse.c,v 1.1 2012/02/18 20:20:37 ishit Exp $

fix security issue (CVE-2009-4413).
patch from Debian BTS.

--- http_parse.c.orig	2008-01-08 12:56:45.000000000 +0000
+++ http_parse.c
@@ -1088,9 +1088,10 @@ httpParseHeaders(int client, AtomPtr url
                                  (v_end >= 0 ? v_end : token_end) -
                                  token_start);
                         do_log(L_WARN, "\n");
+                    } else {
+                        a = atoi(buf + v_start);
+                        cache_control.max_age = a;
                     }
-                    a = atoi(buf + v_start);
-                    cache_control.max_age = a;
                 } else if(token_compare(buf, token_start, token_end,
                                         "s-maxage")) {
                     int a;
@@ -1100,9 +1101,10 @@ httpParseHeaders(int client, AtomPtr url
                                  (v_end >= 0 ? v_end : token_end) -
                                  token_start);
                         do_log(L_WARN, "\n");
+                    } else {
+                        a = atoi(buf + v_start);
+                        cache_control.max_age = a;
                     }
-                    a = atoi(buf + v_start);
-                    cache_control.max_age = a;
                 } else if(token_compare(buf, token_start, token_end,
                                         "min-fresh")) {
                     int a;
@@ -1112,9 +1114,10 @@ httpParseHeaders(int client, AtomPtr url
                                  (v_end >= 0 ? v_end : token_end) -
                                  token_start);
                         do_log(L_WARN, "\n");
+                    } else {
+                        a = atoi(buf + v_start);
+                        cache_control.max_age = a;
                     }
-                    a = atoi(buf + v_start);
-                    cache_control.max_age = a;
                 } else if(token_compare(buf, token_start, token_end,
                                         "max-stale")) {
                     int a;
@@ -1124,9 +1127,10 @@ httpParseHeaders(int client, AtomPtr url
                                  (v_end >= 0 ? v_end : token_end) -
                                  token_start);
                         do_log(L_WARN, "\n");
+                    } else {
+                        a = atoi(buf + v_start);
+                        cache_control.max_stale = a;
                     }
-                    a = atoi(buf + v_start);
-                    cache_control.max_stale = a;
                 } else {
                     do_log(L_WARN, "Unsupported Cache-Control directive ");
                     do_log_n(L_WARN, buf + token_start, 
