# $NetBSD: Makefile,v 1.1 2014/05/02 10:30:30 jihbed Exp $

DISTNAME=	cito-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cito/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/tunnell/cito
COMMENT=	Generic particle-physics software trigger with flash ADCs
#LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
