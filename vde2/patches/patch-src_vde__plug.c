$NetBSD$

Fix bad ctype calls.

--- src/vde_plug.c.orig	2026-08-08 13:52:08.513903724 +0000
+++ src/vde_plug.c
@@ -64,7 +64,7 @@ void write_syslog_entry(char *message)
 	//TNX Giordani-Macchia code from vish.c
 	if ((ssh_client=getenv("SSH_CLIENT"))!=NULL)
 	{
-		for (ip_length=0;ip_length<sizeof(host)&&ssh_client[ip_length]!=0&&!isspace(ssh_client[ip_length]);ip_length++);
+		for (ip_length=0;ip_length<sizeof(host)&&ssh_client[ip_length]!=0&&!isspace((unsigned char)ssh_client[ip_length]);ip_length++);
 		if (ip_length>=sizeof(host))
 			ip_length=sizeof(host)-1;
 		memcpy(host,ssh_client,ip_length);
