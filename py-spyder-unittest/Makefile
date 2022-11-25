# $NetBSD$

DISTNAME=	spyder_unittest-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder_unittest/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder-unittest
COMMENT=	Plugin to run tests from within the Spyder IDE
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-zmq>=23.2.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	spyder>=5.4.0:../../wip/spyder

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
