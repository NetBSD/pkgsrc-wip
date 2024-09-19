# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:31 asau Exp $

DISTNAME=	csa-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math  python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/csa/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://software.incf.org/software/csa/
COMMENT=	The Connection-Set Algebra implemented in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

WRKSRC=		${WRKDIR}/csa-0.0.1

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_csa.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
