# $NetBSD: Makefile,v 1.1 2020/12/19 14:56:04 mef Exp $

DISTNAME=	photutils-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/photutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://photutils.readthedocs.io/en/stable/
COMMENT=	Astropy coordinated module for astronomical photometry
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-scikit-image>=0.14.2:../../math/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.19:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=0.1:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-gwcs>=0.12:../../math/py-gwcs

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
