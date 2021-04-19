# $NetBSD$

DISTNAME=	astroplan-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroplan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://astroplan.readthedocs.io/en/latest/
COMMENT=	Astropy affiliated module for planning astronomical observations
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>1.10:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.4:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-astroquery>=0.3.9:../../wip/py-astroquery

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
