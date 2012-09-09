# $NetBSD: Makefile,v 1.3 2012/09/09 16:10:32 jihbed Exp $
#

DISTNAME=	Delny-0.4.1
PKGNAME=	${PYPKGPREFIX}-delny-0.4.1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/D/Delny/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/flub/delny
COMMENT=	Python module for delaunay triangulation
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/Delny-0.4.1

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/test ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} all.py


.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
