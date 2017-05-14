# $NetBSD$

DISTNAME=	libretro-fuse-20170123
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Fuse
COMMENT=	Libretro core based on the FUSE ZX Spectrum emulator
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	fuse-libretro
GITHUB_TAG=	f834c9b9d0b69d48e8e25b234c86a8227af0c862

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fuse_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fuse_libretro.so

.include "../../mk/bsd.pkg.mk"
