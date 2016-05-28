# $NetBSD: Makefile,v 1.14 2012/10/07 16:23:16 asau Exp $

DISTNAME=	SpeedX-0.1.4d
PKGNAME=	speedx-0.1.4d
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=speedx/}
DISTFILES=	${DEFAULT_DISTFILES} mercrain.s3m.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://medernac.home.cern.ch/medernac/SpeedX/index_en.html
COMMENT=	Car racing game for X

SITES.mercrain.s3m.zip=	http://www.modarchive.com/cgi-bin/download.cgi/M/


GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

post-build:
# XXX should just use find and cpio instead, but cpio isn't on all systems
	${MKDIR} ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/background ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/cars ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/music ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/num ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/road ${WRKDIR}/share
	${CP} -Rf ${WRKSRC}/src/scene ${WRKDIR}/share
	${FIND} ${WRKDIR}/share -type f \! -name "*.png" | ${XARGS} ${RM}

post-install:
	${CP} -Rf ${WRKDIR}/share/* ${PREFIX}/share/speedx
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/speedx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/speedx
	${INSTALL_DATA} ${WRKDIR}/mercrain.s3m ${PREFIX}/share/speedx/music/

.include "../../graphics/png/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
