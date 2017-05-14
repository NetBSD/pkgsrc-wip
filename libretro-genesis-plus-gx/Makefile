# $NetBSD$

DISTNAME=	libretro-genesis-plus-gx-20170420
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the Genesis Plus Sega 8/16 bit emulator

GITHUB_PROJECT=	Genesis-Plus-GX
GITHUB_TAG=	365a28c7349b691e6aaa3ad59b055261c42bd130

USE_TOOLS=	gmake

MAKE_FILE=	Makefile.libretro

BUILD_MAKE_FLAGS+=	SHARED_LIBVORBIS=1

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
BUILD_MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DBYTE_ORDER=BIG_ENDIAN
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/genesis_plus_gx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/genesis_plus_gx_libretro.so

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
