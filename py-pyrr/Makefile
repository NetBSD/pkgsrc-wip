# $NetBSD: Makefile,v 1.1 2014/07/26 09:19:58 jihbed Exp $

DISTNAME=	pyrr-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrr/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/adamlwgriffiths/Pyrr
COMMENT=	3D mathematical functions using NumPy
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
