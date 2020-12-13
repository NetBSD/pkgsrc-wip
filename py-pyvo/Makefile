# $NetBSD$

DISTNAME=	pyvo-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	pyvo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kinoshita@astro.ncu.edu.tw
HOMEPAGE=	https://pyvo.readthedocs.io/en/latest/
COMMENT=	Astropy affiliated Python module for accessing virtual observatories
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-astropy4>=4.2:../../wip/py-astropy4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
