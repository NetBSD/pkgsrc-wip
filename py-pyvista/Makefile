# $NetBSD$

DISTNAME=	pyvista-0.36.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvista/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyvista/pyvista
COMMENT=	Easier Pythonic interface to VTK
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-imageio>=2.5.0:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-Pillow>=0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-appdirs>=0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-scooby>=0.5.1:../../wip/py-scooby

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
