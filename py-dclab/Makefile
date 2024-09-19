# $NetBSD: Makefile,v 1.1 2015/06/13 10:00:34 jihbed Exp $

DISTNAME=	dclab-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dclab/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ZellMechanik-Dresden/dclab
COMMENT=	Data analysis for real-time deformability cytometry
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-nptdms>=0.6.4:../../wip/py-nptdms

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
