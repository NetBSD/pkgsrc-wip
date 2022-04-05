# $NetBSD: Makefile,v 1.1 2020/12/19 14:56:04 mef Exp $

DISTNAME=	photutils-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/photutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://photutils.readthedocs.io/en/stable/
COMMENT=	Astropy coordinated module for astronomical photometry
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-scikit-image>=0.15.0:../../math/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.19:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.0:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=0.1:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-gwcs>=0.16:../../math/py-gwcs
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
