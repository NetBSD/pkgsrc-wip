# $NetBSD: Makefile,v 1.4 2011/08/12 12:55:13 asau Exp $
#

DISTNAME=	gevent-0.13.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/g/gevent/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
