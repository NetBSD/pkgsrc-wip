# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:36:58 jihbed Exp $
#

DISTNAME=	PySPH-0.9beta
PKGNAME=	${PYPKGPREFIX}-pysph-0.9
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/P/PySPH/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysph.googlecode.com/
COMMENT=	General purpose Smoothed Particle Hydrodynamics framework


DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/PySPH-0.9beta

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
