# $NetBSD: Makefile,v 1.4 2014/01/25 10:38:16 thomasklausner Exp $

DISTNAME=	bitarray-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bitarray
COMMENT=	Efficient arrays of booleans -- C extension
LICENSE=	python-software-foundation

PYDISTUTILSPKG=			yes

do-test:
	${RUN} cd ${WRKSRC}/bitarray; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_bitarray.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
