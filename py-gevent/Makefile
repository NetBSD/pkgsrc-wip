# $NetBSD: Makefile,v 1.9 2013/12/06 01:14:19 jihbed Exp $

DISTNAME=	gevent-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/g/gevent/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.1:../../wip/py-greenlet
.include "../../mk/bsd.pkg.mk"
