# $NetBSD: Makefile,v 1.3 2014/01/02 20:46:22 thomasklausner Exp $

DISTNAME=	bitarray-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bitarray/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bitarray
COMMENT=	Efficient arrays of booleans -- C extension
LICENSE=	python-software-foundation

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	${RUN} cd ${WRKSRC}/bitarray; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_bitarray.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
