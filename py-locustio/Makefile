# $NetBSD: Makefile,v 1.1 2015/04/10 18:28:22 angelmm1 Exp $

DISTNAME=	locustio-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=l/locustio/}

MAINTAINER=	angel.medinamoscat@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/locustio
COMMENT=	Python utility for doing distributed load testing of a web site
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-gevent>=1.0.1:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.4.2:../../devel/py-msgpack

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gevent

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/locust \
		${DESTDIR}${PREFIX}/bin/locust-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
