# $NetBSD: Makefile,v 1.1.1.1 2005/02/28 20:27:49 poppnk Exp $
#

DISTNAME=		linuxtv-dvb-apps-1.1.0
CATEGORIES=		wip linux
MASTER_SITES=		http://212.227.36.83/linuxtv/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://212.227.36.83/linuxtv/downloads/
COMMENT=		DVB applications from LinuxTV project

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM= Linux-*-*

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

do-install:
.for bin in ${DVB_BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxtv-dvb/
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxtv-dvb/dvb-c
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-c/* \
		${PREFIX}/share/linuxtv-dvb/dvb-c/
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxtv-dvb/dvb-s
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-s/* \
		${PREFIX}/share/linuxtv-dvb/dvb-s/
	${INSTALL_DATA_DIR} ${PREFIX}/share/linuxtv-dvb/dvb-t
	${INSTALL_DATA} ${WRKSRC}/util/scan/dvb-t/* \
		${PREFIX}/share/linuxtv-dvb/dvb-t/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/linuxtv-dvb/
	${INSTALL_DATA} ${WRKSRC}/util/szap/README \
		${PREFIX}/share/doc/linuxtv-dvb/szap
	${INSTALL_DATA} ${WRKSRC}/util/scan/README \
		${PREFIX}/share/doc/linuxtv-dvb/scan
	${INSTALL_DATA} ${WRKSRC}/util/av7110_loadkeys/README \
		${PREFIX}/share/doc/linuxtv-dvb/av7110_loadkeys


.include "../../mk/bsd.pkg.mk"
