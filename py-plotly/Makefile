# $NetBSD$

DISTNAME=	plotly-4.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plotly/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://plotly.com/python/
COMMENT=	Interactive graphing library for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.24.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-retrying>=1.3.3:../../wip/py-retrying

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
