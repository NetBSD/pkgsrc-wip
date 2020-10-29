# $NetBSD$

DISTNAME=	lazr.restfulclient-0.14.3
PKGNAME=	${PYPKGPREFIX}-lazr-restfulclient-0.14.3
CATEGORIES=	devel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=l/lazr.restfulclient/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/lazr.restfulclient
COMMENT=	Programmable client library that takes advantage
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-distro>=1.5.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=3.1.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wadllib>=1.1.4:../../wip/py-wadllib
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures>=1.3.0:../../devel/py-fixtures
#TEST_DEPENDS+=	# TODO: lazr.authentication>=0
#TEST_DEPENDS+=	# TODO: lazr.restful>=0.11.0
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-wsgi-intercept>=0.4:../../wip/py-wsgi-intercept
TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeTestrunner>=5.2:../../devel/py-ZopeTestrunner

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
