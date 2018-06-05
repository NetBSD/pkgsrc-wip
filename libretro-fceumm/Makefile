# $NetBSD: Makefile,v 1.1 2015/02/04 22:57:29 jmcneill Exp $

DISTNAME=	libretro-fceumm-20180418
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	libretro-fceumm
GITHUB_TAG=	82fd24e28d47c96aff0f3ebf370ea3afc06d6bd1

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/fceumm/
COMMENT=	Libretro core based on the FCEUmm Famicom/NES emulator
LICENSE=	gnu-gpl-v2

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fceumm_libretro.so

.include "../../mk/bsd.pkg.mk"
