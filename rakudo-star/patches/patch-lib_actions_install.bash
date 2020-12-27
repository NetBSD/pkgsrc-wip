$NetBSD$

One part wants bmake, the other wants gmake

--- ./lib/actions/install.bash.orig	2020-10-26 00:18:32.000000000 +0900
+++ ./lib/actions/install.bash	2020-12-27 14:24:37.872924232 +0900
@@ -166,8 +166,8 @@ build_nqp() {
 	perl Configure.pl \
 		--backend="$RSTAR_BACKEND" \
 		"$@" \
-		&& make \
-		&& make install \
+		&& @@GMAKE@@ \
+		&& @@GMAKE@@ install \
 		|| return
 }
 
@@ -178,8 +178,8 @@ build_rakudo() {
 	perl Configure.pl \
 		--backend="$RSTAR_BACKEND" \
 		"$@" \
-		&& make \
-		&& make install \
+		&& @@GMAKE@@ \
+		&& @@GMAKE@@ install \
 		|| return
 }
 
