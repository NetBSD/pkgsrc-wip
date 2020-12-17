# $NetBSD$

DISTNAME=	astroscrappy-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	astroscrappy
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/astroscrappy/
COMMENT=	Astropy affiliated Python module for cosmic ray removal
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.21:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-astropy-helpers-[0-9]*:../../wip/py-astropy-helpers
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../wip/py-scipy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
