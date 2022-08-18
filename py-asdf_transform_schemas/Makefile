# $NetBSD$

DISTNAME=	asdf_transform_schemas-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_transform_schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/asdf_transform_schemas/
COMMENT=	ASDF schemas for validating transform tags
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asdf_standard>=1.0.1:../../wip/py-asdf_standard
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=3:../../devel/py-importlib-resources

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
