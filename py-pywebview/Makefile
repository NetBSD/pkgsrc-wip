# $NetBSD$

DISTNAME=	pywebview-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pywebview/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/r0x0r/pywebview
COMMENT=	Lightweight wrapper around a webview component
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
DEPENDS+=	${PYPKGPREFIX}-proxy_tools-[0-9]*:../../wip/py-proxy_tools

# Optional, but feature 'qt' requires also other modules
#DEPENDS+=	${PYPKGPREFIX}-QtPy-[0-9]*:../../wip/py-qtpy

# Not yet packaged:
#   Needed:
#   Optional:
#DEPENDS+=	${PYPKGPREFIX}-QtPy5-[0-9]*:../../wip/py-qtpy5
#DEPENDS+=	${PYPKGPREFIX}-cefpython3-[0-9]*:../../wip/py-cefpython3
#DEPENDS+=	${PYPKGPREFIX}-pyside2-[0-9]*:../../wip/py-pyside2
#DEPENDS+=	${PYPKGPREFIX}-pyside6-[0-9]*:../../wip/py-pyside6
#DEPENDS+=	${PYPKGPREFIX}-pyqtwebengine-[0-9]*:../../wip/py-pyqtwebengine


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
