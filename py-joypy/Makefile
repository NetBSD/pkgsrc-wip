# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	joypy
GITHUB_TAG=	4273358
DISTNAME=	joypy-0.2.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sbebo/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sbebo/joypy
COMMENT=	Draw ridgeline plots in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.4.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.20.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.11.0:../../math/py-scipy

WRKSRC=		${WRKDIR}/joypy-4273358b7dc601a762c44ee8e09b67b90d6a0afb
USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
