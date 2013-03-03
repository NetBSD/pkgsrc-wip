$NetBSD: patch-filters_syntax-highlighting.sh,v 1.1 2013/03/03 15:25:19 ryo-on Exp $

--- filters/syntax-highlighting.sh.orig	2012-03-18 10:16:27.000000000 +0000
+++ filters/syntax-highlighting.sh
@@ -29,6 +29,6 @@ BASENAME="$1"
 EXTENSION="${BASENAME##*.}"
 
 # map Makefile and Makefile.* to .mk
-[ "${BASENAME%%.*}" == "Makefile" ] && EXTENSION=mk
+[ "${BASENAME%%.*}" = "Makefile" ] && EXTENSION=mk
 
 exec highlight --force -f -I -X -S $EXTENSION 2>/dev/null
