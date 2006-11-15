# $NetBSD: Makefile,v 1.1.1.1 2006/11/15 17:51:47 dhowland Exp $
#

DISTNAME=	mvsis-3.0
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/Respep/Research/mvsis/release/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://embedded.eecs.berkeley.edu/Respep/Research/mvsis/
COMMENT=	Logic synthesis and verification tool

WRKSRC=		${WRKDIR}/mvsis-1.3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

# for some reason, this package has no install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mvsis ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mvsis
	${INSTALL_DATA_DIR} ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.blif ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.mv ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.aut ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/lang.script ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/mcnc5_old.super ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/mcnc_gain.genlib ${PREFIX}/share/mvsis/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/master.mvsisrc ${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/script.check ${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/script.mvs ${PREFIX}/share/mvsis/share

.include "../../mk/bsd.pkg.mk"
