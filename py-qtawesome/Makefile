# $NetBSD$

DISTNAME=	QtAwesome-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QtAwesome/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/qtawesome
COMMENT=	Iconic fonts in PyQt and PySide applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-QtPy>=2.2.0:../../wip/py-qtpy

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
