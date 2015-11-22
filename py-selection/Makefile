# $NetBSD$

DISTNAME=	selection-0.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/s/selection/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/selection/
COMMENT=	API to extract content from HTML & XML documents
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-weblib>=0.1.20:../../wip/py-weblib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
