# $NetBSD$

DISTNAME=	Electrum-4.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/4.6.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.electrum.org/4.6.2/
COMMENT=	Free non-custodial cryptocurrency wallet for Bitcoin
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-certifi>=2025.0.0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.12:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.10:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-aiorpcX>=0.25:../../net/py-aiorpcX
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.20:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-qrcode>=8.2:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-electrum_ecc>=0.0.6:../../wip/py-electrum_ecc
DEPENDS+=	${PYPKGPREFIX}-electrum_aionostr>=0.0.11:../../wip/py-electrum_aionostr
DEPENDS+=	${PYPKGPREFIX}-jsonpatch>=1.33:../../wip/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-attrs>=20.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-dns>=2.2:../../net/py-dns

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

REPLACE_PYTHON=		*.py

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
