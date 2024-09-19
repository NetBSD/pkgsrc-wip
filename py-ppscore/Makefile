# $NetBSD$

DISTNAME=	ppscore-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ppscore/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/8080labs/ppscore/
COMMENT=	Python implementation of the Predictive Power Score
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=   27

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.22.1:../../math/py-scikit-learn

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
