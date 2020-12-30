$NetBSD$

One part wants bmake, the other wants gmake

--- ./lib/actions/install.bash.orig	2020-10-26 00:18:32.000000000 +0900
+++ ./lib/actions/install.bash	2020-12-27 15:10:57.489393386 +0900
@@ -155,7 +155,7 @@ build_moarvm() {
 	perl Configure.pl \
 		"$@" \
 		&& make \
-		&& make install \
+		&& env DESTDIR=@DESTDIR@ make install \
 		|| return
 }
 
@@ -166,8 +166,8 @@ build_nqp() {
 	perl Configure.pl \
 		--backend="$RSTAR_BACKEND" \
 		"$@" \
-		&& make \
-		&& make install \
+		&& env PATH=@PREFIX@/bin gmake \
+		&& env DESTDIR=@DESTDIR@ PATH=@PREFIX@/bin gmake install \
 		|| return
 }
 
@@ -178,8 +178,8 @@ build_rakudo() {
 	perl Configure.pl \
 		--backend="$RSTAR_BACKEND" \
 		"$@" \
-		&& make \
-		&& make install \
+		&& /usr/pkg/bin/gmake \
+		&& env DESTDIR=@DESTDIR@ /usr/pkg/bin/gmake install \
 		|| return
 }
 
