# $NetBSD$

VERSION=	0.6.10
DISTNAME=	${VERSION}
PKGNAME=	${PYPKGPREFIX}-pivy-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=coin3d/}
GITHUB_PROJECT=	pivy
GITHUB_TAG=	${VERSION}
CATEGORIES=	graphics
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/coin3d/pivy
COMMENT=	Python bindings for Coin
LICENSE=	isc

PYTHON_VERSIONS_ACCEPTED=	311
USE_TOOLS+=			pkg-config
USE_LANGUAGES+=			c c++

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/cmake/build.mk"

.include "../../wip/Coin/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/soqt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
