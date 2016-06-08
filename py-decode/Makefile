# $NetBSD: Makefile,v 1.1 2014/11/21 22:07:25 jihbed Exp $

DISTNAME=	pydecode-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydecode/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	${MASTER_SITE_PYPI:=p/pydecode/}
COMMENT=	Dynamic programming toolkit

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
