# $NetBSD$

DISTNAME=	ccdproc-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ccdproc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/ccdproc/
COMMENT=	Astropy coordinated package for CCD data recution in astronomy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	${PYPKGPREFIX}-astropy>=4:../../wip/py-astropy4
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../wip/py-scipy
DEPENDS+=	${PYPKGPREFIX}-scikit-image-[0-9]*:../../wip/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-astroscrappy-[0-9]*:../../wip/py-astroscrappy
DEPENDS+=	${PYPKGPREFIX}-reproject-[0-9]*:../../wip/py-reproject

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
