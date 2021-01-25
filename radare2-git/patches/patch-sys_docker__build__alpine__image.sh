$NetBSD$

--- sys/docker_build_alpine_image.sh.orig	2021-01-25 12:08:13.000000000 +0000
+++ sys/docker_build_alpine_image.sh
@@ -186,7 +186,7 @@ RUN set -o pipefail && \
 			echo "alias q=\"exit\"" >>/root/.bashrc \
 		) \
 	) && ( \
-		[ "$gname" == "root" ] || \
+		[ "$gname" = "root" ] || \
 		( \
 			groupadd -f $gname && \
 			(groupmod -g $gid $gname 2>/dev/null || true) && \
