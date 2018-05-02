# $NetBSD$

DISTNAME=	libretro-gearboy-20180416
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=drhelius/}
GITHUB_PROJECT=	Gearboy
GITHUB_TAG=	d1b9e3fde23821376404c1211c49b8d4dec7a27c

HOMEPAGE=	https://docs.libretro.com/library/gearboy/
COMMENT=	Libretro core for the Gearboy Game Boy / Game Boy Color emulator
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
BUILD_DIRS=	platforms/libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/platforms/libretro/gearboy_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/gearboy_libretro.so

.include "../../mk/bsd.pkg.mk"
