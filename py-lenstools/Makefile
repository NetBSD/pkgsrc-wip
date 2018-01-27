# $NetBSD$

DISTNAME=	lenstools-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lenstools/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lenstools.readthedocs.org/
COMMENT=	Toolkit for Weak Gravitational Lensing analysis
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-emcee>=2.1.0:../../wip/py-emcee
DEPENDS+=	${PYPKGPREFIX}-astropy>=1.1.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
