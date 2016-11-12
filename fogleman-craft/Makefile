# $NetBSD$

DISTNAME=	Craft-${GITHUB_TAG}
PKGNAME=	fogleman-craft-${VERSION}
VERSION=	1.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=fogleman/}
CATEGORIES=	games
LICENSE=	mit

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Simple Minecraft clone written in C
HOMEPAGE=	https://www.michaelfogleman.com/craft/

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

WRKSRC=			${WRKDIR}/Craft-${VERSION}
INSTALLATION_DIRS=	bin

# The default 'install' target wants to install the dependencies it
# had to build in order to build craft(1), but not craft(1) itself. Wut.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/craft ${DESTDIR}${PREFIX}/bin/craft

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
