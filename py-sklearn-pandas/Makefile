# $NetBSD$

DISTNAME=	sklearn-pandas-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sklearn-pandas/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/paulgb/sklearn-pandas
COMMENT=	Pandas integration with sklearn

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.17:../../math/py-scikit-learn

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
