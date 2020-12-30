# $NetBSD$

# TODO: create audio/dumb/Makefile.common ?

DISTNAME=	dumb-2.0.3
PKGNAME=	aldumb-2.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kode54/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kode54/dumb
COMMENT=	Allegro support for audio/dumb
LICENSE=	zlib

USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DBUILD_ALLEGRO4=ON
CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF

BUILD_TARGET=	aldmb

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "amd64"
CMAKE_ARGS+=	-DUSE_SSE=OFF
.endif

INSTALLATION_DIRS+=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/aldumb.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libaldmb.so.2.0 ${DESTDIR}${PREFIX}/lib/
	cd ${WRKSRC} && ${INSTALL_LIB} -l s libaldmb.so.2.0 ${DESTDIR}${PREFIX}/lib/libaldmb.so.2
	cd ${WRKSRC} && ${INSTALL_LIB} -l s libaldmb.so.2 ${DESTDIR}${PREFIX}/lib/libaldmb.so

.include "../../audio/dumb/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
