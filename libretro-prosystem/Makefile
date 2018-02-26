# $NetBSD$

DISTNAME=	libretro-prosystem-20171206
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	prosystem-libretro
GITHUB_TAG=	b8e9241046dc0e5ef9475cad03cd68ee7fe792a5

HOMEPAGE=	https://docs.libretro.com/library/prosystem/
COMMENT=	Libretro core based on the ProSystem Atari 7800 emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prosystem_libretro.so

.include "../../mk/bsd.pkg.mk"
