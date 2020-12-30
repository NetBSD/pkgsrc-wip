# $NetBSD$

DISTNAME=	assimp-5.0.1
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=assimp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://assimp.sourceforge.net/
COMMENT=	Library to import various 3D model formats
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
