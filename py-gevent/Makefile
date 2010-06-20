# $NetBSD: Makefile,v 1.2 2010/06/20 00:31:42 jihbed Exp $
#

DISTNAME=	gevent-0.12.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/g/gevent/
EXTRACT_SUFX=	.gz#md5=97c75039a67593d3f5375fb77f73bbe7

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.gevent.org/
COMMENT=	Python-gevent a coroutine-based Python networking library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/gevent-0.12.2
USE_LANGUAGES=	c c++

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}/greentest; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testrunner.py
	

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
