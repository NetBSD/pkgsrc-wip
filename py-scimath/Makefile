# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:31:47 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
