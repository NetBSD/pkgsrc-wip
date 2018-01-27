# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:27 thomasklausner Exp $

VERS=		1.0-r3067-20090410
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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-yapps2 via py-pycifrw
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
