# $NetBSD$

DISTNAME=	Quandl-3.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	finance python
MASTER_SITES=	https://files.pythonhosted.org/packages/b9/3f/dbe5d8448ea7eb75f079b22d2bdfbb82f6b38e7d6b5e04a5009aff480ffb/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/quandl/quandl-python
COMMENT=	Package for quandl API access
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-inflection>=0.3.1:../../textproc/py-inflection
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=8.4.0:../../devel/py-more-itertools


USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
