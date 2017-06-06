# $NetBSD$

DISTNAME=	libretro-fbalpha2012-20170322
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

COMMENT=	Libretro core based on the FB Alpha arcade emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha2012
GITHUB_TAG=	9146c18ac989c619256d1cb8954d49e728e44ea3

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/svn-current/trunk

MAKE_FILE=	makefile.libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha2012_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha2012_libretro.so

.include "../../mk/bsd.pkg.mk"
