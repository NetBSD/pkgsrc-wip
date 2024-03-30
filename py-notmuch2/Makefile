# $NetBSD$

# XXX: override PYTHON_FOR_BUILD_ONLY= tool in mail/notmuch/Makefile.common
PYTHON_FOR_BUILD_ONLY=		no
PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/pyversion.mk"
.include "../../mail/notmuch/Makefile.common"

WHEEL_NAME=	${DISTNAME:S/notmuch-/notmuch2-/}
PKGNAME=	${PYPKGPREFIX}-${WHEEL_NAME}
CATEGORIES+=	python

MAINTAINER=	mdehling@gmail.com
COMMENT=	Pythonic bindings for the notmuch mail database using CFFI

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

PYSETUPSUBDIR=	bindings/python-cffi

.include "../../mail/notmuch/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
