# $NetBSD$

DISTNAME=	swh.scanner-0.2.0
PKGNAME=	${PYPKGPREFIX}-swh-scanner-0.2.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/swh.scanner/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://forge.softwareheritage.org/diffusion/DTSCN/
COMMENT=	Software Heritage code scanner
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dash>=4.7.6:../../devel/py-dash
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.18.7:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-swh-core>=0.10.0:../../wip/py-swh-core
DEPENDS+=	${PYPKGPREFIX}-ndjson>=0.3.1:../../wip/py-ndjson
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.3:../../www/py-aiohttp


.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
