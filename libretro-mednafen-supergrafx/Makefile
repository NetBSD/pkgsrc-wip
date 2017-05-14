# $NetBSD$

DISTNAME=	libretro-mednafen-supergrafx-20170321
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_SGX
COMMENT=	Libretro core based on the Mednafen SuperGrafx emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-supergrafx-libretro
GITHUB_TAG=	951421d39e6e713395b397c8b2e694aa9eae997d

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_supergrafx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_supergrafx_libretro.so

.include "../../mk/bsd.pkg.mk"
