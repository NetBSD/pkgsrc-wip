# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:28 asau Exp $
#

DISTNAME=	PySPH-0.9beta
PKGNAME=	${PYPKGPREFIX}-pysph-0.9
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/P/PySPH/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysph.googlecode.com/
COMMENT=	General purpose Smoothed Particle Hydrodynamics framework


DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing

WRKSRC=		${WRKDIR}/PySPH-0.9beta

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
