# $NetBSD$

DISTNAME=	healpy-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/healpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/healpy
COMMENT=	Healpix tools package for Python
LICENSE=	gnu-gpl-v2

#DEPENDS+=	${PYPKGPREFIX}-fits>=3.2:../../graphics/py-fits

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	cfitsio/cfitsio.pc.in

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
