# $NetBSD$

DISTNAME=	electrum_aionostr-0.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=e/electrum_aionostr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/electrum_aionostr/
COMMENT=	Fork of aionostr that does not require Coincurve
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.11:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.9.2:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-aiorpcX>=0.22:../../net/py-aiorpcX
DEPENDS+=	${PYPKGPREFIX}-click>=8.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-electrum_ecc>=0.0.6:../../wip/py-electrum_ecc

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE= 27

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
