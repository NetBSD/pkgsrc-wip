# $NetBSD: Makefile,v 1.2 2014/05/05 21:32:13 jihbed Exp $

DISTNAME=	raven-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/raven/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/getsentry/raven-python
COMMENT=	Raven is a client for Sentry

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-login-[0-9]*:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-zconfig-[0-9]*:../../devel/py-zconfig
BUILD_DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
BUILD_DEPENDS+=	${PYPKGPREFIX}-webtest-[0-9]*:../../wip/py-webtest
BUILD_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
BUILD_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
# and many more

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
