# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 18:17:39 daprice Exp $
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
USE_X11=		YES
USE_BUILDLINK3=		YES

post-extract:
	${MV} ${WRKSRC}/HGL_SRC/global_defs.h.orig \
	${WRKSRC}/HGL_SRC/global_defs.h.old

do-build:
	cd ${WRKSRC}/CORE && ${MAKE_ENV} ${SH} install.csh
	cd ${WRKSRC}/HGL_SRC && ${MAKE_ENV} ${SH} install.csh
	cd ${WRKSRC}/ZUKER && ${MAKE_ENV} ${SH} install.csh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/gde
	${INSTALL_DATA_DIR} ${PREFIX}/gde/bin
	${INSTALL_DATA_DIR} ${PREFIX}/gde/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/gde/doc
	${INSTALL_DATA_DIR} ${PREFIX}/gde/db

.for PROGRAM in gde Consto01mask MakeCons PrintStrat Translate \
	heapsortHGL mapview DotPlotTool lrna crna
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PROGRAM} ${PREFIX}/gde/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${PREFIX}/gde/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${PREFIX}/gde/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/CORE/.GDEmenus ${PREFIX}/gde/scripts
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${PREFIX}/gde/doc/
	${INSTALL_DATA} ${WRKSRC}/GDE2.0_manual.ps ${PREFIX}/gde/doc
	${INSTALL_DATA} ${WRKSRC}/db/* ${PREFIX}/gde/db/

.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
