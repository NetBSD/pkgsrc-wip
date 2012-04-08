# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:45 thomasklausner Exp $
#

DISTNAME=	Delny-0.4.1
PKGNAME=	${PYPKGPREFIX}-delny-0.4.1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/D/Delny/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://flub.stuffwillmade.org/delny
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
