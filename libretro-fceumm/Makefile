# $NetBSD: Makefile,v 1.1 2015/02/04 22:57:29 jmcneill Exp $

DISTNAME=	f7e05048fa89e277837ac046bd7f02576b9d5d42
PKGNAME=	libretro-fceumm-20170415
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/libretro-fceumm/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/libretro-fceumm
COMMENT=	Libretro core based on the FCEUmm Famicom/NES emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/libretro-fceumm-${DISTNAME}
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

CFLAGS+=	-DHAVE_ASPRINTF

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fceumm_libretro.so

.include "../../mk/bsd.pkg.mk"
