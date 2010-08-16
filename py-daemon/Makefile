# $NetBSD: Makefile,v 1.5 2010/08/16 12:18:16 jihbed Exp $
#

DISTNAME=	python-daemon-1.5.5
EGG_NAME=	python_daemon-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.8:../../wip/py-lockfile

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-daemon-1.5.5
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_runner.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
