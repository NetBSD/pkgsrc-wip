# $NetBSD$

DISTNAME=	gdstk-0.9.58
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdstk
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdstk/
COMMENT=	C++/Python library for GDSII and OASIS files
LICENSE=	boost-license

USE_LANGUAGES+=	c c++

.include "../../devel/cmake/build.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
