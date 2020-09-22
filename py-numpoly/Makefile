# $NetBSD$

DISTNAME=	numpoly-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/0c/a7/6be96b2df719250f53f4db87ba6b070b1c6cc772019566ee82dceb0ac29e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jonathf/numpoly/
COMMENT=	Polynomials as a numpy datatype
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
