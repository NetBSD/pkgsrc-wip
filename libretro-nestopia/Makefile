# $NetBSD: Makefile,v 1.1 2015/04/10 03:16:17 snj Exp $

DISTNAME=	libretro-nestopia-1.48
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=rdanbrook/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://0ldsk00l.ca/nestopia
COMMENT=	Libretro core based on the Nestopia UE emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	nestopia

BUILD_DIRS=	libretro
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro
INSTALLATION_DIRS+=	share/libretro/nestopia

CFLAGS+=	-DPREFIX=\"${PREFIX}\"

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nestopia_libretro.so
	${INSTALL_DATA} ${WRKSRC}/NstDatabase.xml \
	    ${DESTDIR}${PREFIX}/share/libretro/nestopia

.include "../../mk/bsd.pkg.mk"
