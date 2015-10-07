$NetBSD$

awk: warning: escape sequence `\$' treated as plain `$'
 source line number 56 source file /usr/pkg/libexec/fbsd2pkg/fbsd2pkg.awk
 context is
                    master_sites = >>>  "\$ <<< 
awk: warning: escape sequence `\$' treated as plain `$'
 source line number 212 source file /usr/pkg/libexec/fbsd2pkg/fbsd2pkg.awk
awk: warning: escape sequence `\$' treated as plain `$'
 source line number 220 source file /usr/pkg/libexec/fbsd2pkg/fbsd2pkg.awk

--- fbsd2pkg.awk.orig	2015-09-29 09:52:32.000000000 +0900
+++ fbsd2pkg.awk	2015-10-08 00:13:51.000000000 +0900
@@ -53,7 +53,7 @@ BEGIN {
 	else if ( master_sites ~ "^SF" )
 	    sf_master_sites = master_sites;
 	else if ( master_sites == "CHEESESHOP" )
-	    master_sites = "\${CHEESESHOP}";
+	    master_sites = "\\${CHEESESHOP}";
 	else
 	    gsub("\\${PORTNAME}", portname, master_sites);
     }
@@ -209,7 +209,7 @@ BEGIN {
     else if ( $1 ~ "^PKGNAMEPREFIX" )
     {
 	pkgnameprefix=$2;
-	gsub("\\${PYTHON_PKGNAMEPREFIX}", "\${PYPKGPREFIX}-", pkgnameprefix);
+	gsub("\\${PYTHON_PKGNAMEPREFIX}", "\\${PYPKGPREFIX}-", pkgnameprefix);
     }
     else if ( $1 ~ "^PKGNAMESUFFIX" )
 	pkgnamesuffix=$2;
@@ -217,7 +217,7 @@ BEGIN {
     {
 	# Convert what we can in FreeBSD ports code that's left commented out
 	gsub("STAGEDIR", "DESTDIR", $0);
-	gsub("\\${PYTHON_PKGNAMEPREFIX}", "\${PYPKGPREFIX}-", $0);
+	gsub("\\${PYTHON_PKGNAMEPREFIX}", "\\${PYPKGPREFIX}-", $0);
 	gsub("\\${PORTSDIR}", "../..", $0);
 	
 	if ( ($0 ~ "COPYTREE") && (use_tools !~ "pax") )
