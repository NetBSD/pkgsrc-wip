# $NetBSD$

DISTNAME=	numpy-quaternion-2020.9.5.14.42.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/cb/bb/1ff7d20234ffef492330cb2e6f9f091f0978f3b5356aad0df71d3ad3c091/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/moble/quaternion
COMMENT=	Add a quaternion dtype to NumPy
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
