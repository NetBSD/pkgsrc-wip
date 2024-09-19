# $NetBSD: Makefile,v 1.2 2012/10/03 14:57:08 asau Exp $
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
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mvsis ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mvsis
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.blif ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.mv ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/*.aut ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/lang.script ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/mcnc5_old.super ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA} ${WRKSRC}/examples/mcnc_gain.genlib ${DESTDIR}${PREFIX}/share/mvsis/examples
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/master.mvsisrc ${DESTDIR}${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/script.check ${DESTDIR}${PREFIX}/share/mvsis/share
	${INSTALL_DATA} ${WRKSRC}/share/script.mvs ${DESTDIR}${PREFIX}/share/mvsis/share

.include "../../mk/bsd.pkg.mk"
