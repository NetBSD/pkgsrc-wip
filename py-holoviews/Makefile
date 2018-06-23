# $NetBSD$

DISTNAME=	holoviews-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/d5/9c/d4617468008aa576462d69391a20ce67a95455cd40091915e0f5bfbc878a/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ioam.github.com/holoviews/
COMMENT=	Stop plotting your data - annotate your data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-param>=1.5.0:../../wip/py-param

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
