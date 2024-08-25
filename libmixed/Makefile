# $NetBSD$

DISTNAME=	libmixed-2.0
CATEGORIES=	audio
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Shirakumo/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_TAG=	3f98ad24605fa81368e2dd0dba2d5953ca5c4767

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/Shirakumo/libmixed
COMMENT=	Low-level audio mixer pipeline library
LICENSE=	zlib

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTER=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SIMD=OFF

INSTALLATION_DIRS+=	lib

# XXX Not sure why 'install(TARGETS)' in the CMakeLists isn't working... do
# it manually instead:
do-install:
	${INSTALL} -m0644 ${WRKSRC}/libmixed.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libmixed.so.2.1-0 ${DESTDIR}${PREFIX}/lib
	ln -sf libmixed.so.2.1-0 ${DESTDIR}${PREFIX}/lib/libmixed.so.2
	ln -sf libmixed.so.2 ${DESTDIR}${PREFIX}/lib/libmixed.so

.include "../../mk/bsd.pkg.mk"
