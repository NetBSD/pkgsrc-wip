$NetBSD: patch-ab,v 1.1.1.1 2008/12/25 12:27:03 thomasklausner Exp $

Use standard getopt_long(3) - fixes NetBSD.

--- wordwarvi.c.orig	2008-12-12 02:24:34.000000000 +0000
+++ wordwarvi.c
@@ -13078,7 +13078,7 @@ int main(int argc, char *argv[])
 
 	while (1) {
 		int rc, n; 
-		rc = getopt_long_only(argc, argv, "", wordwarvi_options, &opt);
+		rc = getopt_long(argc, argv, "", wordwarvi_options, &opt);
 		if (rc == -1)
 			break;
 		switch (rc) {
