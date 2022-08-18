# $NetBSD$

DISTNAME=	asdf_wcs_schemas-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_wcs_schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/asdf_wcs_schemas/
COMMENT=	ASDF schemas for validating WCS tags
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.0:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=3:../../devel/py-importlib-resources

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
