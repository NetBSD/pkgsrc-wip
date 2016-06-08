# $NetBSD: Makefile,v 1.1 2014/06/06 22:26:12 jihbed Exp $

DISTNAME=	TSGeom-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=T/TSGeom/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jbn/TSGeom
COMMENT=	Python package for computing simple geometries on TS data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
