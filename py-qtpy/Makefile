# $NetBSD$

DISTNAME=	QtPy-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QtPy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/QtPy/
COMMENT=	Abstraction layer for PyQt5/PySide2/PyQt6/PySide6
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-qt6>=6.7.0:../../x11/py-qt6

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R o-w,g-w ${WRKSRC}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
