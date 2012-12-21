# $NetBSD: Makefile,v 1.3 2012/12/21 18:45:36 jihbed Exp $
#

DISTNAME=	scimath-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://www.enthought.com/repo/ets/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.enthought.com/
COMMENT=	Scientific and Mathematical calculations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

FETCH_USING=	curl
USE_LANGUAGES=	c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
