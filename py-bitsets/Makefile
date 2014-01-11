# $NetBSD: Makefile,v 1.1 2014/01/11 21:34:46 jihbed Exp $

DISTNAME=	bitsets-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	https://pypi.python.org/packages/source/b/bitsets/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/xflr6/bitsets	
COMMENT=	Ordered subsets over a predefined domain
LICENSE=	mit

PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
