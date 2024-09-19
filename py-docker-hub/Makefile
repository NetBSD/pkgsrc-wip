# $NetBSD$

DISTNAME=	docker-hub-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/03/c8/1367bbae2dae2cda827caddf3ca6eeb8e314354e7b538e8cfcf7bae038db/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/amalfra/docker-hub
COMMENT=	Access docker hub from your terminal
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.8.7:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil

TEST_DEPENDS+=	${PYPKGPREFIX}-pytest>=0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
