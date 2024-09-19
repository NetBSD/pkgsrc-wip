$NetBSD$

Avoid using undefined macro.

--- backend/cimxml/indicationlistener.c.orig	2014-11-26 16:26:46.000000000 +0000
+++ backend/cimxml/indicationlistener.c
@@ -455,7 +455,7 @@ static void* establish_listener(int sslM
         else if(dataRead == 0) {
             /* timed out, trying again */
         } else {
-            if ((connFd = accept(listenFd, (__SOCKADDR_ARG) & sin, &sz))<0) {
+            if ((connFd = accept(listenFd, (struct sockaddr *) &sin, &sz))<0) {
                 fprintf(stderr, "Error during accept(), return value was: %d\n", connFd);
                 exit(0);
             }
