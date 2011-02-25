# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:50 thomasklausner Exp $
#

DISTNAME=	symeig-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/mdp-toolkit/mdp-toolkit/2.4/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mdp-toolkit.sourceforge.net/symeig.html
COMMENT=	Symmetrical eigenvalue routines for NumPy
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

TEST_ENV+=	PYTHONPATH=${WRKSRC}/test/
do-test:
	${RUN} cd ${WRKSRC}/test; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} test_symeig.py

.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
