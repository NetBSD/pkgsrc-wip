# $NetBSD$

DISTNAME=	QDarkStyle-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QDarkStyle/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ColinDuquesnoy/QDarkStyleSheet
COMMENT=	The most complete dark/light style sheet for C++/Python
LICENSE=	mit

TOOL_DEPENDS+=     ${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=  ${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-QtPy>=2.2.0:../../wip/py-qtpy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
