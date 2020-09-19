# $NetBSD$

DISTNAME=	yfinance-0.1.54
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	https://files.pythonhosted.org/packages/c2/31/8b374a12b90def92a4e27d0fc595fc43635f395984e36a075244d98bd265/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ranaroussi/yfinance
COMMENT=	Yahoo! Finance market data downloader
LICENSE=	apache-1.1 OR apache-2.0

#DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-multitasking>=0.0.4:../../wip/py-multitasking

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
