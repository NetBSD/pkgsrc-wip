# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 00:22:40 blef Exp $

DISTNAME=	xevilsrc2.02
PKGNAME=	xevil-2.02
CATEGORIES=	games x11
MASTER_SITES=	http://www.xevil.com/download/stable/
EXTRACT_SUFX=	.zip

MAINTAINER=	soren@blef.org
HOMEPAGE=	http://www.xevil.com/
COMMENT=	side scrolling, bloody action game

MAKEFILE=	makefile

USE_X11BASE=	yes
ALL_TARGET=	pkgsrc

MAKE_ENV+=	HOSTTYPE="pkgsrc"

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

do-extract:
	@unzip -aqo ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

post-patch:
	${SED} -e 's|@UNAME@|${UNAME}|' ${WRKSRC}/cmn/utils.cpp > \
		${WRKSRC}/cmn/utils.cpp.fixed
	${MV} ${WRKSRC}/cmn/utils.cpp.fixed ${WRKSRC}/cmn/utils.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/PKGSRC/xevil ${PREFIX}/bin/xevil
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xevil
	${INSTALL_DATA} ${WRKSRC}/instructions/* ${PREFIX}/share/doc/xevil

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
