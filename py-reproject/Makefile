# $NetBSD$

DISTNAME=	reproject-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reproject/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astrofrog/reproject/
COMMENT=	Astropy affiliated package for reprojection of astronomical images
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.13:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.9:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-astropy>=4:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-astropy-healpix>=0.5:../../wip/py-astropy-healpix
DEPENDS+=	${PYPKGPREFIX}-astropy-helpers-[0-9]*:../../math/py-astropy-helpers

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
