# $NetBSD$

DISTNAME=	stats_arrays-0.6.4
PKGNAME=	${PYPKGPREFIX}-stats-arrays-0.6.4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stats_arrays/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/cmutel/stats_arrays
COMMENT=	Standard NumPy array interface for defining uncertain parameters
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.0:../../math/py-scipy


.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
