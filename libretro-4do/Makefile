# $NetBSD$

DISTNAME=	libretro-4do-20170423
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=4DO
COMMENT=	Libretro core for 3DO emulation

GITHUB_PROJECT=	4do-libretro
GITHUB_TAG=	1c3ee3cd4a327ad87fb7fcfd93fddc851119cb6b

USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/4do_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/4do_libretro.so

.include "../../mk/bsd.pkg.mk"
