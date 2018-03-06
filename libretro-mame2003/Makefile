# $NetBSD$

DISTNAME=	libretro-mame2003-20180305
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	mame2003-libretro
GITHUB_TAG=	68d5898290448c758ec1f331672046460cd88dc8

HOMEPAGE=	https://docs.libretro.com/library/mame_2003/
COMMENT=	Libretro core based on the Multiple Arcade Machine Emulator (v0.78)
LICENSE=	no-commercial-use

USE_TOOLS+=	gmake
EXTRACT_USING=	bsdtar

.include "../../mk/endian.mk"

MAKE_FLAGS+=	platform=unix	# doesn't work like other libretro cores weirdly
				# defaults to windows
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	BIGENDIAN=1
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mame2003_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mame2003_libretro.so

.include "../../mk/bsd.pkg.mk"
