# $NetBSD$

DISTNAME=	ft8_lib-0.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=kgoba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kgoba/ft8_lib/
COMMENT=	C++ implementation of FT8 protocol, for use on microcontrollers
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS=	lib bin

post-install:
	cd ${WRKSRC}; ${INSTALL} gen_ft8 ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL} decode_ft8 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
