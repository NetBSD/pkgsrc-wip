# $NetBSD: Makefile,v 1.1 2015/02/05 01:40:45 jmcneill Exp $

DISTNAME=	libretro-gambatte-20171024
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/gambatte/
COMMENT=	Libretro core based on the Gambatte Game Boy Color emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	gambatte-libretro
GITHUB_TAG=	bcfd2df6d946c200fc6e50b0956b209582221492

USE_LANGUAGES=	c c++
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
EXTRACT_USING=	bsdtar

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/gambatte_libretro.so

.include "../../mk/bsd.pkg.mk"
