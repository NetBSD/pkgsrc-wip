# $NetBSD: Makefile,v 1.1 2015/02/04 22:57:29 jmcneill Exp $

DISTNAME=	libretro-fceumm-20171204
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=FCEUmm
COMMENT=	Libretro core based on the FCEUmm Famicom/NES emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	libretro-fceumm
GITHUB_TAG=	56b786df6c3dcfbe6221bcbfed3e66acc7ccb24b

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fceumm_libretro.so

.include "../../mk/bsd.pkg.mk"
