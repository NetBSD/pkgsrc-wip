# $NetBSD: Makefile,v 1.6 2004/04/26 20:35:37 blef Exp $
#

DISTNAME=	yafray-0.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.coala.uniovi.es/~jandro/noname/downloads/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.yafray.org/
COMMENT=	Yet Another Free Raytracer

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes

YAFRAYDIR=		${PREFIX}/share/yafray/
DOCDIR=			${PREFIX}/share/doc/yafray

PTHREAD_OPTS=		require

post-extract:
	${MV} ${WRKSRC}/src/loader/loader.cc ${WRKSRC}/src/loader/loader.cc.in

pre-configure:
	${SED} -e "s|@@YAFRAYDIR@@|${YAFRAYDIR}|g" \
		${WRKSRC}/src/loader/loader.cc.in \
		> ${WRKSRC}/src/loader/loader.cc
do-install:
	${INSTALL_DATA_DIR} ${YAFRAYDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/gram.yafray ${YAFRAYDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/yafray ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
