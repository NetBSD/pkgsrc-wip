# $NetBSD$

DISTNAME=	QtAwesome-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QtAwesome/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/qtawesome
COMMENT=	Iconic fonts in PyQt and PySide applications
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	3110 310 39 38 37

DEPENDS+=	${PYPKGPREFIX}-QtPy>=2.2.0:../../wip/py-qtpy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
