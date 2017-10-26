# $NetBSD: Makefile,v 1.1 2015/02/11 00:16:25 jmcneill Exp $

DISTNAME=	libretro-beetle-pce-fast-20171024
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://github.com/libretro/beetle-pce-fast-libretro
COMMENT=	Libretro core based on the Mednafen PC Engine emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-pce-fast-libretro
GITHUB_TAG=	d2080d754aad8f6d1006e0ce2d03b86612f4a38f

EXTRACT_USING=	bsdtar

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	mednafen/tremor/vorbisidec.pc.in

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
CFLAGS+=	-DBYTE_ORDER=BIG_ENDIAN
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_pce_fast_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_pce_fast_libretro.so

.include "../../mk/bsd.pkg.mk"
