# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:15:24 jihbed Exp $
#

VERS=	0.1.alpha
DISTNAME=	roban-CosmoloPy-68c52f0
EGG_NAME=	CosmoloPy-0.1.alpha
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/roban-//S/C/c/S/P/p/:S/-68c52f0//}-${VERS}
CATEGORIES=	math
MASTER_SITES=	http://download.github.com/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://roban.github.com/CosmoloPy/
COMMENT=	Python for Cosmology
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
