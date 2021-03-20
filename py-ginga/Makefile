# $NetBSD$

DISTNAME=	ginga-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ginga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ginga.readthedocs.io/
COMMENT=	Astronomical image viewer and toolkit
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.14:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	opencv-[0-9]*:../../graphics/opencv
DEPENDS+=	${PYPKGPREFIX}-piexif-[0-9]*:../../graphics/py-piexif
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-gwcs-[0-9]*:../../math/py-gwcs
DEPENDS+=	${PYPKGPREFIX}-qtpy>=1.1:../../wip/py-qtpy
#DEPENDS+=	${PYPKGPREFIX}-pyside-[0-9]*:../../wip/py-pyside
#DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
