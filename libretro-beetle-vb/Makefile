# $NetBSD$

DISTNAME=	libretro-beetle-vb-20171024
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-vb-libretro
GITHUB_TAG=	2b8353257abd61786b80ad5a7de006f65521a8ba

HOMEPAGE=	https://docs.libretro.com/library/beetle_vb/
COMMENT=	Libretro core based on the Mednafen VirtualBoy emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_vb_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_vb_libretro.so

.include "../../mk/bsd.pkg.mk"
