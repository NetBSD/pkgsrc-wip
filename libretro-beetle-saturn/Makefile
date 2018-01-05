# $NetBSD$

DISTNAME=	libretro-beetle-saturn-20171209
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/beetle_saturn/
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	b5ee7662683051ba11a4c383734d9ddaf3b1e37a

EXTRACT_USING=	bsdtar

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_saturn_libretro.so

.include "../../mk/bsd.pkg.mk"
