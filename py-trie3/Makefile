# $NetBSD$

DISTNAME=	PyTrie3-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyTrie3/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/datapublica/pytrie3
COMMENT=	Python implementation of the trie data structure
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_trie.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
