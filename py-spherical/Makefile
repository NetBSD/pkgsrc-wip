# $NetBSD$

DISTNAME=	spherical-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/b8/d6/0abcca29647c4cd5ad6b6a9fe957d33b292d8e904abdb5635e75979da965/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moble/spherical
COMMENT=	Evaluate and transform D matrices, 3-j symbols
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-quaternionic>=0.2.0:../../wip/py-quaternionic
#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
