# $NetBSD$

DISTNAME=	kubernetes-8.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://files.pythonhosted.org/packages/14/77/9b2cf29fa6ec6b774e83e66acce08d75ecddaeaffdd922bcd78f2ff81e9c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kubernetes-client/python
COMMENT=	Python client for kubernetes
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.21.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-ipaddress>=:../../net/py-ipaddress
DEPENDS+=	${PYPKGPREFIX}-certifi>=2017.4.17:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=1.2.0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.1:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.55.0:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-adal>=1.2.1:../../wip/py-adal
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.6.3:../../security/py-google-auth

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
