# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=	PyYAML-3.10
PKGNAME=	${PYPKGPREFIX}-yaml-3.10
CATEGORIES=	textoproc python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyyaml.org/wiki/PyYAML
COMMENT=	YAML parser and emitter for Python
LICENSE=	mit

PYTHON_VERSIONS_INCLUDE_3X= yes

##testing for python != 3.x
do-test:
	${RUN} cd ${WRKSRC}/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
