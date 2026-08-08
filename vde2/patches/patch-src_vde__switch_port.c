$NetBSD$

Fix bad ctype calls.

--- src/vde_switch/port.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_switch/port.c
@@ -843,7 +843,7 @@ static int portsetuser(char *arg)
 		return ENXIO;
 	if ((pw=getpwnam(portuid)) != NULL)
 		portv[port]->user=pw->pw_uid;
-	else if (isdigit(*portuid)) 
+	else if (isdigit((unsigned char)*portuid)) 
 		portv[port]->user=atoi(portuid);
 	else if (strcmp(portuid,"NONE")==0 || strcmp(portuid,"ANY")==0) 
 		portv[port]->user= -1;
@@ -868,7 +868,7 @@ static int portsetgroup(char *arg)
 		return ENXIO;
 	if ((gr=getgrnam(portgid)) != NULL)
 		portv[port]->group=gr->gr_gid;
-	else if (isdigit(*portgid)) 
+	else if (isdigit((unsigned char)*portgid)) 
 		portv[port]->group=atoi(portgid);
 	else if (strcmp(portgid,"NONE")==0 || strcmp(portgid,"ANY")==0) 
 		portv[port]->group= -1;
