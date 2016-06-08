# $NetBSD: Makefile,v 1.4 2012/10/07 11:54:20 asau Exp $
#

DISTNAME=	Delny-0.4.1
PKGNAME=	${PYPKGPREFIX}-delny-0.4.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=D/Delny/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/flub/delny
COMMENT=	Python module for delaunay triangulation
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/Delny-0.4.1

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} all.py


.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
