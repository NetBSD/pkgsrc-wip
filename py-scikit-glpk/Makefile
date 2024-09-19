# $NetBSD$

DISTNAME=	scikit-glpk-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/98/00/7730979f0853595f1e77ac8b0b661bec8b7881b3aa6b89e5c2e2514f6166/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mckib2/scikit-glpk
COMMENT=	Python linprog interface for GLPK
LICENSE=	mit

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
