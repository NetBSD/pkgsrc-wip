# $NetBSD: Makefile,v 1.4 2015/06/10 22:11:10 jihbed Exp $

DISTNAME=	cclib-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cclib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cclib.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Parsers and algorithms for computational chemistry
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

post-extract:
	${MV} ${WRKSRC}/src/scripts/ccget ${WRKSRC}/src/scripts/ccget${PYVERSSUFFIX}
	${MV} ${WRKSRC}/src/scripts/cda ${WRKSRC}/src/scripts/cda${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/testall.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
