# $NetBSD$

DISTNAME=	python_kasa-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-kasa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-kasa/python-kasa
COMMENT=	Python API for TP-Link Kasa and Tapo devices
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-asyncclick>=8.1.7:../../wip/py-asyncclick
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.9:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-mashumaro>=3.14:../../wip/py-mashumaro

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/kasa ${DESTDIR}${PREFIX}/bin/kasa${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
