# $NetBSD: Makefile,v 1.2 2012/10/06 17:22:16 asau Exp $
#

DISTNAME=	bitarray-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bitarray/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bitarray
COMMENT=	Efficient arrays of booleans -- C extension
LICENSE=	python-software-foundation

WRKSRC=	${WRKDIR}/bitarray-0.3.5

PYTHON_VERSIONS_ACCEPTED= 27 26
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/bitarray; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_bitarray.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
