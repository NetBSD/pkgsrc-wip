# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	bitsets-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitsets/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/xflr6/bitsets	
COMMENT=	Ordered subsets over a predefined domain
LICENSE=	mit

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
