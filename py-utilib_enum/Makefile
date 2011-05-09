# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 19:57:43 jihbed Exp $
#

DISTNAME=	pyutilib.enum-1.0.5
PKGNAME=	${PYPKGPREFIX}-utilib_enum-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutilib.enum/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://software.sandia.gov/svn/public/pyutilib/pyutilib.enum
COMMENT=	Variant of the 'enum' package that supports pickling
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyutilib.enum-1.0.5

VERSION=	1.0.5
USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/pyutilib/enum/tests/; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_enum.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
