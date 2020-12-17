# $NetBSD$

DISTNAME=	photutils-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	photutils
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://photutils.readthedocs.io/en/stable/
COMMENT=	Astropy coordinated module for astronomical photometry
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	git>=2:../../devel/git
DEPENDS+=	${PYPKGPREFIX}-scikit-image>=0.14.2:../../math/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.19:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-astropy4>=4.2:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=0.1:../../wip/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-gwcs>=0.12:../../wip/py-gwcs

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init;

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
