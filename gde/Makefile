# $NetBSD: Makefile,v 1.4 2012/09/28 23:43:19 asau Exp $
#

DISTNAME=		GDElinux
PKGNAME=		gde-linux-20031111
CATEGORIES=		local
MASTER_SITES=		http://www.bioafrica.net/GDElinux/

MAINTAINER=		ykim@cs.nmsu.edu
HOMEPAGE=		http://www.bioafrica.net/GDElinux/
COMMENT=		Genetic Data Environment

WRKSRC=			${WRKDIR}/GDE
USE_LINUX=		YES

post-extract:
	${MV} ${WRKSRC}/HGL_SRC/global_defs.h.orig \
	${WRKSRC}/HGL_SRC/global_defs.h.old

do-build:
	cd ${WRKSRC}/CORE && ${MAKE_ENV} ${SH} install.csh
	cd ${WRKSRC}/HGL_SRC && ${MAKE_ENV} ${SH} install.csh
	cd ${WRKSRC}/ZUKER && ${MAKE_ENV} ${SH} install.csh

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/gde
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/gde/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/gde/scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/gde/doc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/gde/db

.for PROGRAM in gde Consto01mask MakeCons PrintStrat Translate \
	heapsortHGL mapview DotPlotTool lrna crna
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${DESTDIR}${PREFIX}/gde/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${DESTDIR}${PREFIX}/gde/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${DESTDIR}${PREFIX}/gde/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/CORE/.GDEmenus ${DESTDIR}${PREFIX}/gde/scripts
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${DESTDIR}${PREFIX}/gde/doc/
	${INSTALL_DATA} ${WRKSRC}/GDE2.0_manual.ps ${DESTDIR}${PREFIX}/gde/doc
	${INSTALL_DATA} ${WRKSRC}/db/* ${DESTDIR}${PREFIX}/gde/db/

.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
