# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	GRPy
PKGNAME=	${PYPKGPREFIX}-grpy-${VERSION}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/G/GRPy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=GRPy&submit=search
COMMENT=	Small GR-oriented package which uses sympy
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.7:../../math/py-sympy

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	0.1

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

GRPy_FILES=	Christoffel.py Riemann.py Tensor.py
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED= 27 26

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
