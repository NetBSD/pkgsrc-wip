# $NetBSD$

DISTNAME=	nomadnet-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nomadnet/}

MAINTAINER=	gdt@lexort.com
HOMEPAGE=	https://github.com/markqvist/nomadnet
COMMENT=	Communicate Freely
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-rns>=0.4.9:../../wip/py-rns
DEPENDS+=	${PYPKGPREFIX}-lxmf>=0.3.1:../../wip/py-lxmf
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1.2:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-qrcode>=0:../../graphics/py-qrcode

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
