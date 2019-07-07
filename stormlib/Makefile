# $NetBSD$

DISTNAME=	stormlib-9.22
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ladislav-zezula/}
GITHUB_PROJECT=	StormLib
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://www.zezula.net/en/mpq/stormlib.html
COMMENT=	Blizzard MPQ archive tool
LICENSE=	mit

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DSTORM_BUILD_TESTS=OFF

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
