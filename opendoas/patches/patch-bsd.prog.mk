$NetBSD$

Use SETUID_ROOT_PERMS and allow building as normal user.

--- bsd.prog.mk.orig	2020-11-01 11:47:22.462380395 +0000
+++ bsd.prog.mk
@@ -22,8 +22,6 @@ install: ${PROG} ${PAM_DOAS} ${MAN}
 	mkdir -p -m 0755 ${DESTDIR}${MANDIR}/man1
 	mkdir -p -m 0755 ${DESTDIR}${MANDIR}/man5
 	cp -f ${PROG} ${DESTDIR}${BINDIR}
-	chown ${BINOWN}:${BINGRP} ${DESTDIR}${BINDIR}/${PROG}
-	chmod ${BINMODE} ${DESTDIR}${BINDIR}/${PROG}
 	[ -n "${PAM_DOAS}" ] && cp ${PAM_DOAS} ${DESTDIR}${PAMDIR}/doas || true
 	[ -n "${PAM_DOAS}" ] && chmod 0644 ${DESTDIR}${PAMDIR}/doas || true
 	cp -f doas.1 ${DESTDIR}${MANDIR}/man1
