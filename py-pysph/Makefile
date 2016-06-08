# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	PySPH-0.9beta
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySPH/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysph.googlecode.com/
COMMENT=	General purpose Smoothed Particle Hydrodynamics framework

DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing

WRKSRC=		${WRKDIR}/PySPH-0.9beta

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # my-multiprocessing

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
