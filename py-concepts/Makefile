# $NetBSD: Makefile,v 1.2 2014/01/17 20:18:23 jihbed Exp $

DISTNAME=	concepts-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/c/concepts/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/xflr6/concepts
COMMENT=	Formal Concept Analysis with Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/concepts-0.2.2

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-bitsets>=0.1.3:../../wip/py-bitsets
.include "../../mk/bsd.pkg.mk"
