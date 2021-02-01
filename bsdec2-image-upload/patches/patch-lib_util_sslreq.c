$NetBSD$

Ignore SIGPIPE globally, backported from upstream commit
5935505d197620010be9366d6e6e84162a39e90c.

--- lib/util/sslreq.c.orig	2020-04-10 22:53:40.000000000 +0000
+++ lib/util/sslreq.c
@@ -120,7 +120,6 @@ sslreq2(const char * host, const char * 
 	SSL * ssl;
 	int readlen;
 	size_t resppos;
-	int on = 1;
 
 	/* Create resolver hints structure. */
 	memset(&hints, 0, sizeof(hints));
@@ -153,10 +152,6 @@ sslreq2(const char * host, const char * 
 	if (r == NULL)
 		return "Could not connect";
 
-	/* Disable SIGPIPE on this socket. */
-	if (setsockopt(s, SOL_SOCKET, SO_NOSIGPIPE, &on, sizeof(on)))
-		return "Could not disable SIGPIPE";
-
 	/* Launch SSL. */
 	if (!SSL_library_init())
 		return "Could not initialize SSL";
