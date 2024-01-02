$NetBSD: patch-an,v 1.4 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/Makefile.m4.orig	2023-12-05 09:53:22.000000000 +0000
+++ sendmail/Makefile.m4
@@ -4,9 +4,10 @@ include(confBUILDTOOLSDIR`/M4/switch.m4'
 define(`confREQUIRE_LIBSM', `true')
 define(`confREQUIRE_SM_OS_H', `true')
 bldPRODUCT_START(`executable', `sendmail')
-define(`bldBIN_TYPE', `G')
+dnl define(`bldBIN_TYPE', `G')
 define(`bldINSTALL_DIR', `')
 define(`bldSOURCES', `main.c alias.c arpadate.c bf.c collect.c conf.c control.c convtime.c daemon.c deliver.c domain.c envelope.c err.c headers.c macro.c map.c mci.c milter.c mime.c parseaddr.c queue.c ratectrl.c readcf.c recipient.c sasl.c savemail.c sched.c sfsasl.c shmticklib.c sm_resolve.c srvrsmtp.c stab.c stats.c sysexits.c timers.c tlsh.c tls.c trace.c udb.c usersmtp.c util.c version.c ')
+APPENDDEF(`bldSOURCES',`blacklist.c ')
 PREPENDDEF(`confENVDEF', `confMAPDEF')
 bldPUSH_SMLIB(`sm')
 bldPUSH_SMLIB(`smutil')
@@ -68,7 +69,7 @@ ifdef(`confNO_STATISTICS_INSTALL',, `bld
 divert(bldTARGETS_SECTION)
 
 install-set-user-id: bldCURRENT_PRODUCT ifdef(`confNO_HELPFILE_INSTALL',, `install-hf') ifdef(`confNO_STATISTICS_INSTALL',, `install-st') ifdef(`confNO_MAN_BUILD',, `install-docs')
-	${INSTALL} -c -o ${S`'BINOWN} -g ${S`'BINGRP} -m ${S`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${M`'BINDIR}
+	${INSTALL} -c -m ${S`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${M`'BINDIR}
 	for i in ${sendmailTARGET_LINKS}; do \
 		rm -f $$i; \
 		${LN} ${LNOPTS} ${M`'BINDIR}/sendmail $$i; \
@@ -76,7 +77,7 @@ install-set-user-id: bldCURRENT_PRODUCT 
 
 define(`confMTA_LINKS', `${DESTDIR}${UBINDIR}/newaliases ${DESTDIR}${UBINDIR}/mailq ${DESTDIR}${UBINDIR}/hoststat ${DESTDIR}${UBINDIR}/purgestat')
 install-sm-mta: bldCURRENT_PRODUCT
-	${INSTALL} -c -o ${M`'BINOWN} -g ${M`'BINGRP} -m ${M`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${M`'BINDIR}/sm-mta
+	${INSTALL} -c -m ${M`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${M`'BINDIR}/sm-mta
 	for i in confMTA_LINKS; do \
 		rm -f $$i; \
 		${LN} ${LNOPTS} ${M`'BINDIR}/sm-mta $$i; \
@@ -84,14 +85,14 @@ install-sm-mta: bldCURRENT_PRODUCT
 
 install-hf:
 	if [ ! -d ${DESTDIR}${HFDIR} ]; then mkdir -p ${DESTDIR}${HFDIR}; else :; fi
-	${INSTALL} -c -o ${UBINOWN} -g ${UBINGRP} -m 444 helpfile ${DESTDIR}${HFFILE}
+	${INSTALL} -c -m 444 helpfile ${DESTDIR}${HFFILE}
 
 install-st: statistics
 	if [ ! -d ${DESTDIR}${STDIR} ]; then mkdir -p ${DESTDIR}${STDIR}; else :; fi
-	${INSTALL} -c -o ${SBINOWN} -g ${UBINGRP} -m ifdef(`confSTMODE', `confSTMODE', `0600') statistics ${DESTDIR}${STPATH}
+	${INSTALL} -c -m ifdef(`confSTMODE', `confSTMODE', `0600') statistics ${DESTDIR}${STPATH}
 
 install-submit-st: statistics ${DESTDIR}${MSPQ}
-	${INSTALL} -c -o ${MSPQOWN} -g ${GBINGRP} -m ifdef(`confSTMODE', `confSTMODE', `0600') statistics ${DESTDIR}${MSPQ}/${MSPSTFILE}
+	${INSTALL} -c -m ifdef(`confSTMODE', `confSTMODE', `0600') statistics ${DESTDIR}${MSPQ}/${MSPSTFILE}
 
 divert(0)
 bldPRODUCT_END
