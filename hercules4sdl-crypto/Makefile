# $NetBSD$

GITHUB_PROJECT=	crypto
GITHUB_TAG=	837705eff938ca044f2eab5f1ea5cd83b2b0ece7 # 5 Jan 2021
DISTNAME=	hercules4sdl-crypto-2.5
PKGREVISION=	20210105
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of crypto for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/crypto64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libcrypto64.a libcrypto_pic.a

.include "../../mk/bsd.pkg.mk"
