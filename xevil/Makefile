# $NetBSD: Makefile,v 1.6 2004/12/02 16:39:10 thomasklausner Exp $

DISTNAME=	xevilsrc2.02r2
PKGNAME=	xevil-2.02
WRKSRC=		${WRKDIR}
CATEGORIES=	games x11
MASTER_SITES=	http://www.xevil.com/download/stable/
EXTRACT_SUFX=	.zip

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://www.xevil.com/
COMMENT=	Side scrolling, bloody action game

MAKEFILE=	makefile

USE_BUILDLINK3=	yes
USE_X11BASE=	yes
BUILD_TARGET=	pkgsrc

MAKE_ENV+=	HOSTTYPE="pkgsrc"

post-patch:
	${SED} -e 's|@UNAME@|${UNAME}|' ${WRKSRC}/cmn/utils.cpp > \
		${WRKSRC}/cmn/utils.cpp.fixed
	${MV} ${WRKSRC}/cmn/utils.cpp.fixed ${WRKSRC}/cmn/utils.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/PKGSRC/xevil ${PREFIX}/bin/xevil
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xevil
	${INSTALL_DATA} ${WRKSRC}/instructions/* ${PREFIX}/share/doc/xevil

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
