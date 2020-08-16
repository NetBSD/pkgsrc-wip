$NetBSD$

* Remove the `-e' option of echo as it is not portable

--- ob-cache/test-profiles/pts/system-decompress-gzip-1.1.0/install.sh.orig	2020-08-14 21:42:45.350390380 +0000
+++ ob-cache/test-profiles/pts/system-decompress-gzip-1.1.0/install.sh
@@ -6,7 +6,8 @@ echo $? > ~/install-exit-status
 cat > system-decompress-gzip << EOT
 #!/bin/sh
 ${GZIP} -d --stdout qt-everywhere-opensource-src-5.0.0.tar.gz > /dev/null 2>&1
-echo -e "\n" >> \${LOG_FILE}
+echo >> \${LOG_FILE}
+echo >> \${LOG_FILE}
 EOT
 chmod +x system-decompress-gzip
 
