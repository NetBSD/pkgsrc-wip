$NetBSD$

Running 'make test':
undefined reference to `rpl_strerror'

https://gitlab.com/gnutls/gnutls/issues/81

--- tests/dtls/dtls-stress.c.orig	2015-01-19 17:38:09.000000000 +0000
+++ tests/dtls/dtls-stress.c
@@ -346,8 +346,7 @@ static void _process_error_or_timeout(in
 
 static void rperror(const char *name)
 {
-	fprintf(stdout, "%i %s| %s: %s\n", run_id, role_name, name,
-		strerror(errno));
+	fprintf(stdout, "%i %s| %s\n", run_id, role_name, name);
 }
 
 // }}}
