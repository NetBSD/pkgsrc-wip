# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	pyutilib.enum-1.0.5
PKGNAME=	${PYPKGPREFIX}-utilib_enum-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutilib.enum/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/svn/public/pyutilib/pyutilib.enum
COMMENT=	Variant of the 'enum' package that supports pickling
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pyutilib.enum-1.0.5

VERSION=	1.0.5
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/pyutilib/enum/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_enum.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
