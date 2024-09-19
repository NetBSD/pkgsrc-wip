# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:46 thomasklausner Exp $

DISTNAME=	sppy-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sppy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/sppy/
COMMENT=	Sparse matrix package based on Eigen
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
