# $NetBSD: Makefile,v 1.2 2003/06/03 02:19:01 blef Exp $

DISTNAME=	SpeedX-0.1.4d
PKGNAME=	speedx-0.1.4d
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=speedx/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mercrain.s3m.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://medernac.home.cern.ch/medernac/SpeedX/index_en.html
COMMENT=	car racing game for X

SITES_mercrain.s3m.zip=	http://www.modarchive.com/cgi-bin/download.cgi/M/

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

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

.include "../../graphics/png/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
