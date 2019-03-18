# $NetBSD$

DISTNAME=	paho-mqtt-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/25/63/db25e62979c2a716a74950c9ed658dce431b5cb01fde29eb6cba9489a904/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	eclipse-license

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.6.6:../../devel/py-lama
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
