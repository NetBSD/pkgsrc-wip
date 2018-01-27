# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:39 thomasklausner Exp $

DISTNAME=	concepts-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/concepts/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/xflr6/concepts
COMMENT=	Formal Concept Analysis with Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/concepts-0.2.2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run-tests.py

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-bitsets>=0.1.3:../../wip/py-bitsets
.include "../../mk/bsd.pkg.mk"
