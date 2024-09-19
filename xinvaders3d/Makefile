# $NetBSD: Makefile,v 1.35 2012/10/06 11:55:01 asau Exp $

DISTNAME=		xinvaders3d-1.3.6
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		https://www.ibiblio.org/pub/Linux/games/arcade/invaders/
EXTRACT_SUFX=		.src.tar.gz
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Vector-graphics Space Invaders clone for X11

WRKSRC=			${WRKDIR}/xinvaders3d
INSTALLATION_DIRS=	bin share/xinvaders3d

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xinvaders3d
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/xinvaders3d
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/xinvaders3d
	${INSTALL_DATA} ${WRKSRC}/xinvaders3d.lsm ${DESTDIR}${PREFIX}/share/xinvaders3d
	${INSTALL_PROGRAM} ${WRKSRC}/xinv3d ${DESTDIR}${PREFIX}/bin/xinv3d

.include "../../mk/bsd.prefs.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
