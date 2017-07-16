# $NetBSD: Makefile,v 1.1 2015/02/11 00:16:25 jmcneill Exp $

DISTNAME=	libretro-mednafen-pce-fast-20170409
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/beetle-pce-fast-libretro
COMMENT=	Libretro core based on the Mednafen PC Engine emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-pce-fast-libretro
GITHUB_TAG=	a24a7b76d854cffa8d9896650c52491dc8d4d6d5

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
EXTRACT_USING=	bsdtar

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
