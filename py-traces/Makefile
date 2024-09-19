# $NetBSD$

DISTNAME=	traces-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/93/e8/dbdea1159fbbcc50e825e0ea9895c001fa1b2046a095619d33d83c243a9c/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/datascopeanalytics/traces
COMMENT=	Library for unevenly-spaced time series analysis
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.4:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
