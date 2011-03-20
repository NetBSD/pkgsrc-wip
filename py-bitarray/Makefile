# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:48:46 jihbed Exp $
#

DISTNAME=	bitarray-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bitarray/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bitarray
COMMENT=	Efficient arrays of booleans -- C extension
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/bitarray-0.3.5

PYTHON_VERSIONS_ACCEPTED= 27 26
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/bitarray; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_bitarray.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
