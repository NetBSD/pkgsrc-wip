$Id: patch-src_sxid.c,v 1.1 2014/10/30 08:54:37 bartoszkuzma Exp $

getopt_long_only is not available in NetBSD

--- src/sxid.c.orig	2013-08-07 11:09:12.000000000 +0000
+++ src/sxid.c
@@ -85,8 +85,7 @@ int main(int argc, char *argv[])
 	umask(077);
 	config_options.flags = 0x00;
 
-	while ((opt = getopt_long_only(argc, argv, "nhVlkc:", cmd_options,
-						NULL)) != EOF) {
+	while ((opt = getopt_long(argc, argv, "nhVlkc:", cmd_options, NULL)) != EOF) {
 		switch (opt) {
 		case 'c':
 			confname = optarg;
