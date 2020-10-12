# $NetBSD: Makefile,v 1.6 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	symeig-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mdp-toolkit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mdp-toolkit.sourceforge.net/symeig.html
COMMENT=	Symmetrical eigenvalue routines for NumPy
LICENSE=	modified-bsd

USE_LANGUAGES=	c fortran
PYDISTUTILSPKG=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/test/
do-test:
	${RUN} cd ${WRKSRC}/test; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} test_symeig.py

.include "../../mk/blas.buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
