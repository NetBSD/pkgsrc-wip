# $NetBSD$

DISTNAME=	goless-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/goless/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/packages/source/g/goless/
COMMENT=	Provides a Go-like concurrent programming style in Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-gevent>=1.0.2:../../net/py-gevent

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gevent

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
