$NetBSD$

--- bsd.prog.mk.orig	2020-11-02 13:01:52.000000000 +0000
+++ bsd.prog.mk
@@ -23,7 +23,7 @@ install: ${PROG} ${PAM_DOAS} ${MAN}
 	[ -n "${PAM_DOAS}" ] && mkdir -p -m 0755 ${DESTDIR}${PAMDIR} || true
 	mkdir -p -m 0755 ${DESTDIR}${MANDIR}/man1
 	mkdir -p -m 0755 ${DESTDIR}${MANDIR}/man5
-	cp -f ${PROG} ${DESTDIR}${BINDIR}
+	install -o ${BINOWN} -g 0 -m ${BINMODE} ${PROG} ${DESTDIR}${BINDIR}
 	chown ${BINOWN}:${BINGRP} ${DESTDIR}${BINDIR}/${PROG}
 	chmod ${BINMODE} ${DESTDIR}${BINDIR}/${PROG}
 	[ -n "${PAM_DOAS}" ] && cp ${PAM_DOAS} ${DESTDIR}${PAMDIR}/doas || true
