# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:42 asau Exp $
#

DISTNAME=	griddata-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://griddata-python.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/griddata-python/
COMMENT=	Interpolate irregularly spaced data to a grid
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
