# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	spfpm-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyfixedpoint/pyfixedpoint/spfpm-0.6/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyfixedpoint.sourceforge.net/
COMMENT=	Tools for arithmetic on fixed-point (binary) numbers
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testFixedPoint.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
