$NetBSD: patch-src_thor_thor.cxx,v 1.2 2013/05/09 14:40:49 makoto Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/thor/thor.cxx.orig	2013-05-03 14:19:08.000000000 +0000
+++ src/thor/thor.cxx
@@ -63,7 +63,7 @@ void thor::tx_init(SoundBase *sc)
 	videoText();
 	strSecXmtText = progdefaults.THORsecText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 	cptr = 0;
 }
 
