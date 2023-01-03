$NetBSD$

Fix quoting for additional command-line parameters

--- jigasi.sh.orig	2023-01-03 13:50:40.995992729 +0000
+++ jigasi.sh
@@ -29,4 +29,4 @@ fi
 
 if [ -z "$JIGASI_MAX_MEMORY" ]; then JIGASI_MAX_MEMORY=3072m; fi
 
-LD_LIBRARY_PATH=$libs exec java -Xmx$JIGASI_MAX_MEMORY -Djava.library.path=$libs $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass $@
+LD_LIBRARY_PATH=$libs exec java -Xmx$JIGASI_MAX_MEMORY -Djava.library.path=$libs $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass "$@"
