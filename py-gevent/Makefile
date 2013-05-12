# $NetBSD: Makefile,v 1.6 2013/05/12 20:17:42 cheusov Exp $
#

DISTNAME=	gevent-0.13.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/g/gevent/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6

.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
