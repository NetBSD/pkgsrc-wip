# $NetBSD$

DISTNAME=	euclidean-1.0.0b3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/b0/c5/4babd2bcd9a4b2f333cc156f5b02419b33c5a737552251368eca7cf00ed7/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/keystonetowersystems/euclidean
COMMENT=	Euclidean Geometry Library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.6.0:../../devel/py-multipledispatch

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
