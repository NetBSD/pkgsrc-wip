# $NetBSD: Makefile,v 1.1 2015/08/11 21:43:24 jihbed Exp $

DISTNAME=	scikit-image-0.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-image.org
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.9.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.9:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
