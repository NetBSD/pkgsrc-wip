# $NetBSD$

DISTNAME=	nameko-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nameko/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.nameko.io/
COMMENT=	Microservices framework for Python
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-astroid>=2.4.2:../../devel/py-astroid
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.1:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.3.0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.15:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.1:../../devel/py-mccabe
BUILD_DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3.1:../../devel/py-codestyle
BUILD_DEPENDS+=	${PYPKGPREFIX}-pylint>=1.7.1:../../devel/py-pylint
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=4.3.1:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.3.3:../../devel/py-test-timeout
BUILD_DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.23:../../www/py-urllib3
BUILD_DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.48.0:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-dns>=1.16.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-amqp>=2.5.2:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-eventlet>=0.29.1:../../wip/py-eventlet
DEPENDS+=	${PYPKGPREFIX}-kombu>=4.2.0,<5:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-mock>=1.2:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-path.py>=6.2:../../devel/py-path.py
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.9:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.0.0:../../devel/py-wrapt

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
