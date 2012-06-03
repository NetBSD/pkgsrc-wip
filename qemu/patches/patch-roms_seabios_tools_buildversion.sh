$NetBSD: patch-roms_seabios_tools_buildversion.sh,v 1.1 2012/06/03 09:00:55 ryo-on Exp $

--- roms/seabios/tools/buildversion.sh.orig	2012-06-01 09:17:03.000000000 +0000
+++ roms/seabios/tools/buildversion.sh
@@ -15,7 +15,7 @@ VERSION="${VERSION}-`date +"%Y%m%d_%H%M%
 echo "Version: ${VERSION}"
 
 # Build header file
-if [ "$VAR16MODE" == "VAR16" ]; then
+if [ "$VAR16MODE" = "VAR16" ]; then
     cat > ${OUTFILE} <<EOF
 #include "types.h"
 char VERSION[] VAR16 = "${VERSION}";
