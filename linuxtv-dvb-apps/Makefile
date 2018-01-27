# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:26 othyro Exp $
#

DISTNAME=		linuxtv-dvb-apps-1.1.1
CATEGORIES=		linux
MASTER_SITES=		https://www.linuxtv.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.linuxtv.org/
COMMENT=		DVB applications from LinuxTV project

USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

do-build:
	cd ${WRKSRC} && ${GMAKE}

DVB_BIN_FILES= \
	util/dvbdate/dvbdate \
	util/dvbnet/dvbnet \
	util/dvbtraffic/dvbtraffic \
	util/scan/scan \
	util/szap/czap \
	util/szap/szap \
	util/szap/tzap \
	util/szap/femon \
	util/av7110_loadkeys/av7110_loadkeys

INSTALLATION_DIRS=	bin

do-install:
.for bin in ${DVB_BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/linuxtv-dvb/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-c
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-c/* \
		${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-c/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-s
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-s/* \
		${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-s/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-t
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-t/* \
		${DESTDIR}${PREFIX}/share/linuxtv-dvb/dvb-t/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/linuxtv-dvb/
	${INSTALL_DATA} ${WRKSRC}/util/szap/README \
		${DESTDIR}${PREFIX}/share/doc/linuxtv-dvb/szap
	${INSTALL_DATA} ${WRKSRC}/util/scan/README \
		${DESTDIR}${PREFIX}/share/doc/linuxtv-dvb/scan
	${INSTALL_DATA} ${WRKSRC}/util/av7110_loadkeys/README \
		${DESTDIR}${PREFIX}/share/doc/linuxtv-dvb/av7110_loadkeys


.include "../../mk/bsd.pkg.mk"
