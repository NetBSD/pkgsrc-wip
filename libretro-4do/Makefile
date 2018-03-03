# $NetBSD$

DISTNAME=	libretro-4do-20170724
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	4do-libretro
GITHUB_TAG=	368a8eb2b8eb61a17d1d5be6edc37775820634c7

HOMEPAGE=	https://docs.libretro.com/library/4do/
COMMENT=	Libretro core for 3DO emulation

USE_TOOLS+=	gmake
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/4do_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/4do_libretro.so

.include "../../mk/bsd.pkg.mk"
