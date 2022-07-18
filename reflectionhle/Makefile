# $NetBSD: Makefile,v 1.1 2015/08/19 19:21:33 yhardy Exp $

GITHUB_PROJECT=	ReflectionHLE
GITHUB_TAG=	release-${PKGVERSION_NOREV}
DISTNAME=	reflectionhle-20211231
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ReflectionHLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ReflectionHLE/ReflectionHLE/
COMMENT=	Port of Keen Dreams, the 3D Catacomb games and Wolfenstein 3D
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/

.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
