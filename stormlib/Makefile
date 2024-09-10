# $NetBSD$

DISTNAME=	stormlib-9.26
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ladislav-zezula/}
GITHUB_PROJECT=	StormLib
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	http://www.zezula.net/en/mpq/stormlib.html
COMMENT=	Blizzard MPQ archive tool
LICENSE=	mit

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DSTORM_BUILD_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
