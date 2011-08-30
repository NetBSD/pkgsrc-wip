$NetBSD: patch-desktop_scripts_soffice.sh,v 1.1 2011/08/30 20:37:37 ftigeot Exp $

--- clone/libs-core/desktop/scripts/soffice.sh.orig	2011-06-14 22:00:33.000000000 +0000
+++ clone/libs-core/desktop/scripts/soffice.sh
@@ -87,6 +87,7 @@ NetBSD|OpenBSD|FreeBSD|DragonFly)
     sd_prog1="$sd_prog/../basis-link/program"
     sd_prog2="$sd_prog/../basis-link/ure-link/lib"
     LD_LIBRARY_PATH=$sd_prog1:$sd_prog2${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
+    LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/pkg/lib:/usr/X11R7/lib
     JAVA_HOME=$(javaPathHelper -h libreoffice-java 2> /dev/null)
     export LD_LIBRARY_PATH
     if [ -n "${JAVA_HOME}" ]; then
