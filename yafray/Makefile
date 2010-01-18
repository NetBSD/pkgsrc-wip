# $NetBSD: Makefile,v 1.13 2010/01/18 09:38:35 thomasklausner Exp $
#

DISTNAME=	yafray-0.0.7
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES= http://yafray.org/sec/2/downloads/

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://www.yafray.org/
COMMENT=	Yet Another Free Raytracer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

YAFRAYDIR=		${PREFIX}/share/yafray/
DOCDIR=			${PREFIX}/share/doc/yafray

PTHREAD_OPTS=		require

SUBST_CLASSES+=     patch
SUBST_MESSAGE.patch=	Make yafray search the grammar at the right place.
SUBST_STAGE.patch=  post-patch
SUBST_FILES.patch=  src/loader/loader.cc
SUBST_SED.patch=    -e "s|/usr/local/etc|${YAFRAYDIR}|"

do-install:
	${INSTALL_DATA_DIR} ${YAFRAYDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/gram.yafray ${YAFRAYDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/loader/.libs/yafray ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/yafraycore/.libs/libyafraycore.so ${PREFIX}/lib

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
