# $NetBSD$

DISTNAME=	asdf_astropy-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/asdf_astropy/
COMMENT=	ASDF serialization support for astropy objects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-astropy>=5.0.4:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.0:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-numpy>0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>0:../../wip/py-asdf_coordinates_schemas
DEPENDS+=	${PYPKGPREFIX}-asdf_transform_schemas>=0.2.2:../../wip/py-asdf_transform_schemas
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-packaging>=16.0:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
