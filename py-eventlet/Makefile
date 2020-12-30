# $NetBSD$

DISTNAME=	eventlet-0.29.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eventlet/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://eventlet.net
COMMENT=	Highly concurrent networking library
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-dns>=1.16.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.3:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
