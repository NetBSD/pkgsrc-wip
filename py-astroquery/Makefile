# $NetBSD$

DISTNAME=	astroquery-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	astroquery
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://astroquery.readthedocs.io/en/latest/
COMMENT=	Astropy coordinated Python module for querying astronomical databases
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-keyring>=21.2.1:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../wip/py-astropy4
DEPENDS+=	${PYPKGPREFIX}-pyvo>=1.0:../../wip/py-pyvo

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
