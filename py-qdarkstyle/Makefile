# $NetBSD$

DISTNAME=	QDarkStyle-3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QDarkStyle/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ColinDuquesnoy/QDarkStyleSheet
COMMENT=	The most complete dark/light style sheet for C++/Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-qtpy>=2.2.0:../../wip/py-qtpy

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
