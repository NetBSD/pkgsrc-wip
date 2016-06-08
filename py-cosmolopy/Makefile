# $NetBSD: Makefile,v 1.3 2015/01/31 23:41:28 jihbed Exp $

DISTNAME=	CosmoloPy-0.1.104
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CosmoloPy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://roban.github.com/CosmoloPy/
COMMENT=	Python for Cosmology
LICENSE=	mit

WRKSRC=	${WRKDIR}/CosmoloPy-0.1.104

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
