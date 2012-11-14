# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:14 othyro Exp $
#

DISTNAME=	GRPy
PKGNAME=	${PYPKGPREFIX}-grpy-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/G/GRPy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=GRPy&submit=search
COMMENT=	Small GR-oriented package which uses sympy
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.7:../../math/py-sympy

VERSION=	0.1

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

GRPy_FILES=	Christoffel.py Riemann.py Tensor.py
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
PY_PATCHPLIST=		yes

INSTALLATION_DIRS=	${PYSITELIB}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testtensor.py

do-install:
	for a in ${GRPy_FILES}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/${PYSITELIB}/$$a; \
	done

.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
