# $NetBSD$

DISTNAME=	ginga-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ginga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ginga.readthedocs.io/
COMMENT=	Astronomical image viewer and toolkit
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.14:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.0:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.2.1:../../graphics/py-Pillow
DEPENDS+=	opencv-[0-9]*:../../graphics/opencv
DEPENDS+=	${PYPKGPREFIX}-piexif-[0-9]*:../../graphics/py-piexif
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3.2:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-gwcs-[0-9]*:../../wip/py-gwcs
DEPENDS+=	${PYPKGPREFIX}-QtPy>=2.0.1:../../wip/py-qtpy
#DEPENDS+=	${PYPKGPREFIX}-pyside-[0-9]*:../../wip/py-pyside
#DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-exifread>=2.3.2:../../graphics/py-exifread
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.15:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-astroquery>=0.3.5:../../wip/py-astroquery
DEPENDS+=	${PYPKGPREFIX}-photutils>0:../../wip/py-photutils
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cairo>0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-qt5>0:../../x11/py-qt5

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
