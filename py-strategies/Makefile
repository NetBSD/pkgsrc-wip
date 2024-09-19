# $NetBSD$

DISTNAME=	strategies-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://files.pythonhosted.org/packages/a1/49/67ce5aeaa43fc498951befd4aaf55968ba178c21fee2b68a15408d9b6c79/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/logpy/strategies
COMMENT=	Python library for control flow programming.
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0:../../devel/py-multipledispatch
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.9.0:../../devel/py-toolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
