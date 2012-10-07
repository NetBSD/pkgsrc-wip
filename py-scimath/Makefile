# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scimath-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://www.enthought.com/repo/ets/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.enthought.com/
COMMENT=	Scientific and Mathematical calculations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
