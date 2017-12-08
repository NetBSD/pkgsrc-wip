# $NetBSD$

DISTNAME=	libretro-bluemsx-20171116
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=BlueMSX
COMMENT=	Libretro core for accurate MSX/MSX2/ColecoVision/SVI/SG-1000 emulation
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	blueMSX-libretro
GITHUB_TAG=	cb6133979ea624c7ce1247051bc185a42fa9d342

EXTRACT_USING=	bsdtar
MAKE_FILE=	Makefile.libretro
USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

# For strcasestr
# See dc61b353c3bea0c088b3f827cfbd864460b112a0, pull/33
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_BSD_SOURCE -D_NETBSD_SOURCE
.elif ${OPSYS} == "SunOS"
CFLAGS+=	-D__EXTENSIONS__
.elif ${OPSYS} != "Linux"
CFLAGS+=	-D_GNU_SOURCE -D_BSD_SOURCE
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/bluemsx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/bluemsx_libretro.so

.include "../../mk/bsd.pkg.mk"
