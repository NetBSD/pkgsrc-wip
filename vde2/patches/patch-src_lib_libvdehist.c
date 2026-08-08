$NetBSD$

Fix bad ctype calls.

--- src/lib/libvdehist.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/lib/libvdehist.c
@@ -297,16 +297,16 @@ void vdehist_mgmt_to_term(struct vdehist
 						char *message=st->vlinebuf;
 						//fprintf(stderr,"MSG1 \"%s\"\n",message);
 						while (*message != '\0' &&
-								!(isdigit(message[0]) &&
-									isdigit(message[1]) &&
-									isdigit(message[2]) &&
-									isdigit(message[3])))
+								!(isdigit((unsigned char)message[0]) &&
+									isdigit((unsigned char)message[1]) &&
+									isdigit((unsigned char)message[2]) &&
+									isdigit((unsigned char)message[3])))
 							message++;
 						if (strncmp(message,"0000",4)==0)
 							st->vindata=1;
-						else if (isdigit(message[1]) &&
-								isdigit(message[2]) &&
-								isdigit(message[3])) {
+						else if (isdigit((unsigned char)message[1]) &&
+								isdigit((unsigned char)message[2]) &&
+								isdigit((unsigned char)message[3])) {
 							if(message[0]=='1') {
 								message+=5;
 								vdehist_termwrite(st->termfd,message,strlen(message));
