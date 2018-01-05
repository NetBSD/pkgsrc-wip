# $NetBSD$

DISTNAME=	libretro-prboom-20170707
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/prboom/
COMMENT=	Libretro core for Doom
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	1b5c4e469fb87fa87c0f130f53096ebe78268cad
EXTRACT_USING=	bsdtar

USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prboom_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prboom_libretro.so

.include "../../mk/bsd.pkg.mk"
