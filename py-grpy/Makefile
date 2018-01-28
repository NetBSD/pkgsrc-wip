# $NetBSD: Makefile,v 1.7 2014/06/01 12:49:42 thomasklausner Exp $

VERSION=	0.2
DISTNAME=	GRPy0.2
PKGNAME=	${PYPKGPREFIX}-grpy-${VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GRPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/GRPy
COMMENT=	Small GR-oriented package which uses sympy
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.

USE_LANGUAGES=	# none

NO_BUILD=	yes
GRPy_FILES=	Christoffel.py Riemann.py Tensor.py
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PY_PATCHPLIST=	yes

INSTALLATION_DIRS=	${PYSITELIB}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testtensor.py

do-install:
	for a in ${GRPy_FILES}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/${PYSITELIB}/$$a; \
	done

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.7:../../math/py-sympy
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
