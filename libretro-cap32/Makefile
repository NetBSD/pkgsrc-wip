# $NetBSD$

DISTNAME=	libretro-cap32-20171109
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/caprice32/
COMMENT=	Libretro core based on the Caprice32 Amstrad CPC emulator
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	3e14cebabb3d58dd33990158a2379f3759975409

USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/cap32_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/cap32_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
