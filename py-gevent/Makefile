# $NetBSD: Makefile,v 1.3 2010/07/17 00:49:41 jihbed Exp $
#

DISTNAME=	gevent-0.13.0.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/g/gevent/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/gevent-0.13.0
USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py
	
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
