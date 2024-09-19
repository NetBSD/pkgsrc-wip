$NetBSD: patch-ADMsmb.c,v 1.1 2012/12/03 13:10:03 othyro Exp $

Corrects reference and removes incorrect cast.

--- ADMsmb.c.orig	2003-06-17 12:50:47.000000000 +0000
+++ ADMsmb.c
@@ -139,7 +139,7 @@ int ADMsmb (u_long ip, char *netbioz)
     {
       usleep (100000);
 
-      if (recvfrom (socket_client, buffer2,sizeof(buffer2), 0, (struct sockaddr *) &sin_dst, &(int) longueur) != -1)
+      if (recvfrom (socket_client, buffer2,sizeof(buffer2), 0, (struct sockaddr *) &sin_dst, &longueur) != -1)
 	{         
 
 	  if (nmb2->rep_num != 0)
