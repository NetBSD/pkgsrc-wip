# $NetBSD: Makefile,v 1.4 2003/09/02 02:31:40 xtraeme Exp $
#

DISTNAME=	yafray-0.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.coala.uniovi.es/~jandro/noname/downloads/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.yafray.org/
COMMENT=	Yet Another Free Raytracer

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

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

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
