$NetBSD: patch-src_frontends_meta-input_uade123.sh,v 1.1 2012/12/09 15:25:12 othyro Exp $

Fixes portability failure.

--- src/frontends/meta-input/uade123.sh.orig	2009-10-29 21:01:12.000000000 +0000
+++ src/frontends/meta-input/uade123.sh
@@ -14,7 +14,7 @@ fname=`echo $2| sed -e s/["file:"]*//`
 
 case $1 in
         play)
-		if [ "$3" == "0" ]; then
+		if [ "$3" = "0" ]; then
 		  subsong=""
 		else
 		  subsong="--subsong $3"
