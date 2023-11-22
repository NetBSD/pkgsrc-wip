# $NetBSD$

DISTNAME=	trio-websocket-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio-websocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/trio-websocket
COMMENT=	WebSocket library for Trio
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-trio>=0.14:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-wsproto>=0.14:../../www/py-wsproto

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
