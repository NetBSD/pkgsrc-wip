# $NetBSD$

VERSION=	0.38.2
DISTNAME=	notmuch-${VERSION}
WHEEL_NAME=	notmuch2-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${WHEEL_NAME}
CATEGORIES=	mail python
MASTER_SITES=	https://notmuchmail.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://notmuchmail.org/
COMMENT=	Pythonic bindings for the notmuch mail indexer
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPSUBDIR=	bindings/python-cffi

.include "../../mail/notmuch/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
