# $NetBSD$

DISTNAME=	ibmiotf-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://files.pythonhosted.org/packages/78/05/029ca6f78b788a3c55157fd11bb63922d002d75df982ffb8243f450a750e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ibm-watson-iot/iot-python
COMMENT=	Python Client for IBM Watson IoT Platform
LICENSE=	eclipse-license

#DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.12:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-paho-mqtt>=1.4.0:../../wip/py-paho-mqtt

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
