# $NetBSD$

DISTNAME=	VVVVVVV-0.0.0.20200110
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=TerryCavanagh/}
GITHUB_PROJECT=	VVVVVV
GITHUB_TAG=	9e5e9f3e670a0cc48475a20486b0630e83ae14b4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TerryCavanagh/VVVVVV
COMMENT=	2D puzzle platform video game with gravity reversal
LICENSE=	vvvvvv-license

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS+=	desktop_version
BUILD_DIRS+=		desktop_version

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
