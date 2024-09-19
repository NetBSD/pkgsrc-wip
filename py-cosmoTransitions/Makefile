# $NetBSD$

DISTNAME=	cosmoTransitions-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cosmoTransitions/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/clwainwright/CosmoTransitions
COMMENT=	Zero-temperature cosmological phase transitions
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0.11:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.11:../../math/py-scipy

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.8
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
