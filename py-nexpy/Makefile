# $NetBSD: Makefile,v 1.1 2014/10/03 16:59:00 jihbed Exp $

DISTNAME=	NeXpy-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=N/NeXpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nexpy.github.io/nexpy/
COMMENT=	Python GUI to analyze NeXus data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.2.1:../../devel/py-h5py
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pyside-qt4.8>=1.2.1:../../wip/py-pyside
.include "../../mk/bsd.pkg.mk"
