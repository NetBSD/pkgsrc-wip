# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	pyamg-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pyamg.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pyamg
COMMENT=	Algebraic multigrid solvers in Python
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
