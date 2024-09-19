# $NetBSD: Makefile,v 1.1 2015/02/09 21:41:06 jihbed Exp $

DISTNAME=	ecos-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ecos/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/embotech/ecos
COMMENT=	Embedded Cone Solver
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/ecos-1.1.0

BUILD_TARGET=	_ecos.so

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
#DEPENDS+=	atlas>=3.11.11:../../wip/atlas
.include "../../mk/bsd.pkg.mk"
