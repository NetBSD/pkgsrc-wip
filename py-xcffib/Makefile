# $NetBSD$

DISTNAME=	xcffib-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xcffib/}

HOMEPAGE=	https://github.com/tych0/xcffib
COMMENT=	XCB binding for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1.0:../../devel/py-cffi

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
