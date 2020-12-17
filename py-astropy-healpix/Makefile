# $NetBSD$

DISTNAME=	astropy-healpix-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	astropy-healpix
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/astropy-healpix
COMMENT=	Hierarchical Equal Area isoLatitude Pixelisation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.11.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-astropy4>=4:../../wip/py-astropy4

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
