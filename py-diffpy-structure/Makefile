# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:21 asau Exp $
#

VERS=	1.0-r3067-20090410
DISTNAME=	diffpy.Structure-${VERS}
EGG_NAME=	diffpy.Structure-1.0_r3067_20090410
PKGNAME=	${PYPKGPREFIX}-diffpy-structure-${VERS}
CATEGORIES=	biology
MASTER_SITES=	http://www.diffpy.org/packages/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.diffpy.org/
COMMENT=	Crystal structure container and parsers for structure formats
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pycifrw>=3.1.4:../../wip/py-pycifrw

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
