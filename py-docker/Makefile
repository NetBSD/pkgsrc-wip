# $NetBSD$

DISTNAME=	docker-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/b3/48/014af5285463adb8079f32f603c0d6d19c16d92a113ebacc6b07522dcff5/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/docker/docker-py
COMMENT=	Python library for the Docker Engine API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
#DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.57.0:../../www/py-websocket-client

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
