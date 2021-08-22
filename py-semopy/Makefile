# $NetBSD$

DISTNAME=	semopy-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://semopy.com
COMMENT=	Structural Equation Modeling Optimization in Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.3:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.8:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.22.1:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.12.2:../../math/py-statsmodels


.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
