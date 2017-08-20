$NetBSD$

Provide the possibility to set the default PLUGINCONFDIR for munin-node plugins.
This will allow different sysconfdirs based on the operating system.

--- src/node/node.c.orig	2017-08-19 16:40:56.000000000 +0000
+++ src/node/node.c
@@ -44,7 +44,7 @@ static char* host = "";
 static char* plugin_dir = PLUGINDIR;
 static char* spoolfetch_dir = "";
 static char* client_ip = "-";
-static char* pluginconf_dir = "/etc/munin/plugin-conf.d";
+static char* pluginconf_dir = PLUGINCONFDIR;
 
 static int handle_connection();
 
