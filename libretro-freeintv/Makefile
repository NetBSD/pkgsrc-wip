# $NetBSD$

DISTNAME=	libretro-freeintv-20180215
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	FreeIntv
GITHUB_TAG=	1c4959359573619c65d789a89ecd3b5f05d30ca2

HOMEPAGE=	https://docs.libretro.com/library/freeintv/
COMMENT=	Libretro core for Mattel Intellivision emulation
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DWORDS_BIGENDIAN -DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/freeintv_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/freeintv_libretro.so

.include "../../mk/bsd.pkg.mk"
