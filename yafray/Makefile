# $NetBSD: Makefile,v 1.15 2012/10/07 19:59:30 asau Exp $
#

DISTNAME=	yafray-0.0.7
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://yafray.org/sec/2/downloads/

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://www.yafray.org/
COMMENT=	Yet Another Free Raytracer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

YAFRAYDIR=		${PREFIX}/share/yafray/
DOCDIR=			${PREFIX}/share/doc/yafray

PTHREAD_OPTS=		require

SUBST_CLASSES+=		patch
SUBST_MESSAGE.patch=	Make yafray search the grammar at the right place.
SUBST_STAGE.patch=	post-patch
SUBST_FILES.patch=	src/loader/loader.cc
SUBST_SED.patch=	-e "s|/usr/local/etc|${YAFRAYDIR}|"

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${YAFRAYDIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/gram.yafray ${DESTDIR}${YAFRAYDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/loader/.libs/yafray ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/yafraycore/.libs/libyafraycore.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
